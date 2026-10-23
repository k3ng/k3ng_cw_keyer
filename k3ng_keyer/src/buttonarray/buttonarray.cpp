#include "Arduino.h"
#include "buttonarray.h"

/* contributed by W6IPA */

void Button::InitLimits(uint8_t step){
  /* 
  
  typical button values:
  
    0: -56 - 46
    1: 47 - 131
    2: 132 - 203
    3: 203 - 264
    
  */

    int32_t button_value;
    int32_t lower_button_value;
    int32_t higher_button_value;

    // Bugfix: these three were cast to uint32_t, but for the first button (step==0) the "virtual
    // neighbor" at step-1 makes the inner expression legitimately negative (matching the "0: -56 - 46"
    // example above) - casting a negative float to an unsigned type is undefined behavior in C++, and in
    // practice collapsed lower_button_value (and so low_limit_) to 0 on at least one real toolchain.
    // Button::Pressed()'s low-bound check is a strict ">", so a button-0 press reading exactly 0 (very
    // plausible - it's the lowest step, often a dead short to ground) then failed to match its own
    // button, looking identical to "no button pressed" (GitHub #148 follow-up). Casting to int32_t
    // instead preserves the intended negative low_limit_ for button 0 and changes nothing for every
    // other button (step/step+1 are never negative, so these values are unaffected there).
    button_value = int32_t(max_value * (float(step * r2_value)/float((step * r2_value) + r1_value)));
    lower_button_value = int32_t(max_value * (float((step-1) * r2_value)/float(((step-1) * r2_value) + r1_value)));
    higher_button_value = int32_t(max_value * (float((step+1) * r2_value)/float(((step+1) * r2_value) + r1_value)));
    low_limit_= (button_value - ((button_value - lower_button_value)/2));
    high_limit_= (button_value + ((higher_button_value - button_value)/2));
    step_ = step;
}

void Button::InitLimits(uint8_t step, int32_t low_limit, int32_t high_limit){
    low_limit_ = low_limit;
    high_limit_ = high_limit;
    step_ = step;
}

bool Button::Pressed(int32_t analog_reading){
    if ((analog_reading > low_limit_) && (analog_reading <=  high_limit_)) {
        return true;
    } 
    return false;
}
int32_t Button::high_limit(){
    return high_limit_;
}

int32_t Button::low_limit(){
    return low_limit_;
}

// Add all buttons in incremental order
void ButtonArray::AddAll(){
    size_t index;
    if (reversed_) {
        index = nb_buttons_ - 1;
    } 
    for(size_t i = 0; i < nb_buttons_; i++)
    {
        if (reversed_) {
            Add(i, index);
            index --;
        } else {
            Add(i, i);
        }
    }
}


// Adds a single button to the array
// Takes a step (rank in the resistor ladder), and the index in the button array.
void ButtonArray::Add(uint8_t step, uint8_t index){
    Button button;
    button.InitLimits(step);
    button_array_[index] = button;
    high_limit_ = max(button.high_limit() , high_limit_);
}

void ButtonArray::Add(uint8_t step, uint8_t index, int32_t low_limit, int32_t high_limit){
    Button button;
    button.InitLimits(step, low_limit, high_limit);
    button_array_[index] = button;
    high_limit_ = max(high_limit, high_limit_);
}

int32_t ButtonArray::high_limit(){
    return high_limit_;
}

int32_t ButtonArray::low_limit(uint8_t index){
    if (index < nb_buttons_) {
        return button_array_[index].low_limit();
    }
    return 0;
}

int32_t ButtonArray::high_limit(uint8_t index){
    if (index < nb_buttons_) {
        return button_array_[index].high_limit();
    }
    return 0;
}

int8_t ButtonArray::ReadButtons(){
    // Bugfix (GitHub #148): this used to do analog_line_read_average = (analog_line_read_average +
    // analog_read_temp) / 2 once per sample - not a real average of the NUMBER_OF_BUTTON_READS_TO_AVERAGE
    // samples, but a decaying-weight scheme dominated by whichever in-range sample happened to land last -
    // and silently discarded any sample reading above high_limit_ instead of counting it as evidence
    // against a press. A first fix here replaced that with a true mean of the in-range samples, but that
    // introduced a worse regression: a mechanical button's contact bounce/RC settling ramps the ADC
    // reading down from the "not pressed" rail, through every OTHER (higher-numbered) button's voltage
    // range in turn, before settling on the one actually pressed - all of these buttons share one
    // resistor ladder and one pin. Averaging raw voltages across that transient skews the result toward
    // whichever range the signal spent the most time passing through while settling, which is reliably
    // the highest-numbered button, regardless of which one was actually pressed (confirmed on hardware:
    // every one of buttons 1-3 resolved to button 3).
    //
    // Classify each sample independently into its own matching button (or "no button") first, then take
    // whichever got an outright majority of the votes - this only cares about which state the samples
    // spent most of their time in, not the magnitude of any transient in between, so as long as a genuine
    // press is held for more than half of this read's sample count (true for any normal human press) the
    // correct button wins even with a few transient samples mixed in from other ranges along the way.
    //
    // Bugfix (GitHub #148, hardware-confirmed): the majority-vote above assumed the mechanical bounce/
    // settling transient was brief relative to the whole read. Hardware testing with a raw-reading
    // diagnostic showed otherwise - pressing button 1 or 2 would often read a raw value well into button
    // 3's range for the ENTIRE read, not just a few samples at the start, because back-to-back
    // analogRead() calls with no delay between them (19 reads take under 1ms total on AVR) can complete
    // well before a real mechanical contact has finished bouncing/settling - mechanical bounce routinely
    // lasts several ms to tens of ms. A vote among 19 samples all taken during that same still-settling
    // window doesn't help if none of them reflect the final, fully-seated contact resistance yet. Spread
    // the reads across the typical bounce duration instead of taking them back-to-back, so most of them
    // land after the contact has actually settled.
    #define BUTTON_READ_SETTLE_DELAY_MS 2
    int8_t votes[MAX_ARRAY_BUTTONS] = {0};
    uint8_t no_button_votes = 0;

    for (byte x = 0; x < NUMBER_OF_BUTTON_READS_TO_AVERAGE; x++){
        if (x > 0) { delay(BUTTON_READ_SETTLE_DELAY_MS); }
        uint32_t analog_read_temp = analogRead(pin_);
        int8_t matched = -1;
        if (analog_read_temp <= high_limit_){
            for (size_t b = 0; b < nb_buttons_; b++) {
                if (button_array_[b].Pressed(analog_read_temp)) {
                    matched = b;
                    break;
                }
            }
        }
        if (matched >= 0) {
            votes[matched]++;
        } else {
            no_button_votes++;
        }
    }

    int8_t best_button = -1;
    uint8_t best_votes = no_button_votes;
    for (size_t b = 0; b < nb_buttons_; b++) {
        if (votes[b] > best_votes) {
            best_votes = votes[b];
            best_button = b;
        }
    }

    if ((best_button >= 0) && (best_votes > (NUMBER_OF_BUTTON_READS_TO_AVERAGE / 2))) {
        last_pressed_ms = millis();
        return best_button;
    }

    return -1;
}
// returns true if analog reading indicate a pressed button
bool ButtonArray::AnyPressed() {
  if (analogRead(pin_) <= high_limit_) {
    return true;
  }
  return false;
}
// returns the index of the pressed button or -1 if none pressed
int8_t ButtonArray::Pressed() {
    if (AnyPressed() && ((millis() - last_pressed_ms) > DEBOUNCE_MS )){
        return ReadButtons();
    }
    return -1;
}
// returns true if button at the provided index is pressed
bool ButtonArray::Pressed(uint8_t index) {
    uint32_t analog_read_temp =0;
    analog_read_temp = analogRead(pin_);
    if ((analog_read_temp <= high_limit_) && ( index < nb_buttons_)) {
        Button button = button_array_[index];
        return button.Pressed(analog_read_temp);
    }
    return false;
}
// Return true as long as the indicated button is held and the deadline not reached.
bool ButtonArray::Held(uint8_t index, uint32_t deadline) {
    if (AnyPressed() && 
    (millis() < deadline) && 
    (ReadButtons() == index)) {
        return true;
    }
    return false;
}

// Return true as long as the indicated button is held
bool ButtonArray::Held(uint8_t index) {
    if (AnyPressed() && (ReadButtons() == index)) {
        return true;
    }
    return false;
}
