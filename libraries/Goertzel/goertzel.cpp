#include "goertzel.h"

/*


  Goertzel formula audio detector

  This code comes from http://www.skovholm.com/cwdecoder , http://www.skovholm.com/decoder11.ino

  Hjalmar skovholm Hansen, Oz1jhm <hjh@skovholm.com>




*/

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h" 
#else
#include "WProgram.h"
#endif



float coeff = 0;
float Q1 = 0;
float Q2 = 0;
float sine = 0;
float cosine = 0;  
//float sampling_freq = GOERTZ_SAMPLING_FREQ;
//float target_freq = GOERTZ_TARGET_FREQ;
//float n = GOERTZ_SAMPLES_FLOAT; 
int testData[GOERTZ_SAMPLES];
int audioInPin = 0;
int realstate = LOW;
int realstatebefore = LOW;
int filteredstate = LOW;
unsigned long laststarttime = 0;
int magnitudelimit = 100;
float magnitude = 0;

//////////////////////////////
// Noise Blanker time which //
// shall be computed so     //
// this is initial          //
//////////////////////////////

int nbtime = GOERTZ_NOISE_BLANKER_INITIAL_MS;        


Goertzdetector::Goertzdetector(){}


void Goertzdetector::init(int _audioInPin){
  // The basic goertzel calculation

  int k = 0;
  float	omega = 0;
  //k = (int) (0.5 + ((n * target_freq) / sampling_freq));
  k = (int) (0.5 + (((float)GOERTZ_SAMPLES * (float)GOERTZ_TARGET_FREQ) / (float)GOERTZ_SAMPLING_FREQ));
  //omega = (2.0 * PI * k) / n;
  omega = (2.0 * PI * k) / (float) GOERTZ_SAMPLES;
  sine = sin(omega);
  cosine = cos(omega);
  coeff = 2.0 * cosine;

  audioInPin = _audioInPin;

}

int Goertzdetector::detecttone(){


  // The basic where we get the tone

  
  for (char index = 0; index < GOERTZ_SAMPLES; index++){
    testData[index] = analogRead(audioInPin);
  }

  for (char index = 0; index < GOERTZ_SAMPLES; index++){
	  float Q0;
	  Q0 = coeff * Q1 - Q2 + (float) testData[index];
	  Q2 = Q1;
	  Q1 = Q0;	
  }

  float magnitudeSquared = (Q1*Q1)+(Q2*Q2)-Q1*Q2*coeff;  // we do only need the real part //
  
  magnitude = sqrt(magnitudeSquared);

  Q2 = 0;
  Q1 = 0;

  
  /////////////////////////////////////////////////////////// 
  // here we will try to set the magnitude limit automatic //
  ///////////////////////////////////////////////////////////


  if (magnitude > GOERTZ_MAGNITUDE_LIMIT_LOW){
    magnitudelimit = (magnitudelimit + ((magnitude - magnitudelimit) / GOERTZ_MOVING_AVERAGE_FILTER));  /// moving average filter
  } else {
	  magnitudelimit = GOERTZ_MAGNITUDE_LIMIT_LOW;
  }
  
  ////////////////////////////////////
  // now we check for the magnitude //
  ////////////////////////////////////

  if (magnitude > ((float) magnitudelimit * (float) GOERTZ_MAGNITUDE_THRESHOLD)){
    realstate = HIGH; 
  } else {
    realstate = LOW; 
  }
  
  ///////////////////////////////////////////////////// 
  // here we clean up the state with a noise blanker //
  /////////////////////////////////////////////////////
 
  if (realstate != realstatebefore){
    laststarttime = millis();
  }

  if ((millis()-laststarttime) > nbtime){
    if (realstate != filteredstate){
      filteredstate = realstate;
    }
  }


  realstatebefore = realstate;

  return(filteredstate);

 }
