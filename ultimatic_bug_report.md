# k3ng CW Keyer — Ultimatic Mode Bug Report
**Two defects found and corrected in Ultimatic paddle logic**
SP5DNA — March 2026

> *I am not a software developer. This analysis and the fixes were developed with the assistance of Claude (Anthropic AI). I would not have been able to identify or correct these defects on my own.*

---

## Bug #1 — Ultimatic mode entry disables dit/dah buffers

| | |
|---|---|
| **File** | k3ng_keyer.ino |
| **Functions** | command mode `case 211` (line 7804), serial CLI `case 'D'` (line 12995) |
| **Affected mode** | ULTIMATIC |
| **Severity** | Critical — brief press during an element is silently lost |

### Description

Every time Ultimatic mode was activated via the command mode paddle (letter D) or the serial CLI command D, the firmware explicitly set both `dit_buffer_off` and `dah_buffer_off` to `1`. This caused the element-length timing loop (`loop_element_lengths`) to erase the opposite-paddle buffer immediately after each element, before `service_dit_dah_buffers()` had a chance to consume it.

### Symptom vs. expected behaviour

| Observed (buggy) | Expected (correct) |
|---|---|
| Hold DAH, briefly press DIT and release before DAH ends → only DAH is sent. DIT is silently discarded. | Hold DAH, briefly press DIT and release before DAH ends → DAH–DIT is sent. The brief DIT press is remembered and fires after the inter-element space. |

### Root cause

The buffer-off flags are stored in EEPROM-backed configuration. Once set to `1` they persist across reboots. The line in `loop_element_lengths`:

```cpp
// Culprit — loop_element_lengths, lines 7413–7416
if ((being_sent == SENDING_DIT) || (being_sent == SENDING_DAH)){
    if (configuration.dit_buffer_off) {dit_buffer = 0;}  // erases memory latch
    if (configuration.dah_buffer_off) {dah_buffer = 0;}  // erases memory latch
}
```

This line itself is correct and intentional (it implements the optional "buffers off" feature). The defect is that the Ultimatic mode-entry code switched this feature on unconditionally.

### Fix

Change the two mode-entry locations from setting the flags to `1` to setting them to `0`.

**Before — command mode (case 211, line 7804):**
```cpp
configuration.keyer_mode = ULTIMATIC;
keyer_mode_before = ULTIMATIC;
configuration.dit_buffer_off = 1;   // BUG: disables memory latch
configuration.dah_buffer_off = 1;   // BUG: disables memory latch
```

**After — command mode (case 211):**
```cpp
configuration.keyer_mode = ULTIMATIC;
keyer_mode_before = ULTIMATIC;
configuration.dit_buffer_off = 0;   // FIX: keep memory latch active
configuration.dah_buffer_off = 0;   // FIX: keep memory latch active
```

**Before — serial CLI (case 'D', line 12995):**
```cpp
configuration.keyer_mode = ULTIMATIC;
configuration.dit_buffer_off = 1;   // BUG
configuration.dah_buffer_off = 1;   // BUG
```

**After — serial CLI (case 'D'):**
```cpp
configuration.keyer_mode = ULTIMATIC;
configuration.dit_buffer_off = 0;   // FIX
configuration.dah_buffer_off = 0;   // FIX
```

### Note on EEPROM persistence

If the device previously ran the buggy firmware, the EEPROM will contain `dit_buffer_off=1`. After flashing the fix, enter command mode and press D once to overwrite the stored values with `0`.

---

## Bug #2 — Phantom element after both paddles released mid-element

| | |
|---|---|
| **File** | k3ng_keyer.ino |
| **Function** | `check_paddles()` — cases `DIT_CLOSURE_DAH_ON` and `DAH_CLOSURE_DIT_ON` |
| **Approximate lines** | 5924–5938, 5955–5969 |
| **Affected mode** | ULTIMATIC |
| **Severity** | High — spurious element appended to sequence |

### Description

The Ultimatic state machine in `check_paddles()` tracks which paddle was touched last using the static variable `last_closure`. When both paddles are held and the keyer is in state `DIT_CLOSURE_DAH_ON` (DIT repeating, DAH was pressed later), the opposite paddle's buffer (`dah_buffer`) is set by `check_dah_paddle()` during the DIT transmission. If both paddles are released during that DIT, `dah_buffer` remains `1` when `check_paddles()` is next called — because `check_dah_paddle()` only sets the flag when the pin is LOW; it never clears it. The state machine then transitions to `DAH_CLOSURE_DIT_OFF` and `service_dit_dah_buffers()` fires an unintended DAH.

### Reproduction scenario

| | |
|---|---|
| **Step 1** | Press and hold DAH. |
| **Step 2** | While DAH sounds, press DIT. DAH finishes; DIT starts (correct Ultimatic behaviour). |
| **Step 3** | Release **both** paddles while DIT is still sounding. |
| **Result** | DAH–DIT–DAH is sent. The final DAH is spurious. |
| **Expected** | DAH–DIT only. After both paddles are released the sequence stops. |

### Root cause

In state `DIT_CLOSURE_DAH_ON`, when `dit_buffer` is `0` (element just ended) but `dah_buffer` is `1`, the original code unconditionally transitioned to `DAH_CLOSURE_DIT_OFF` without verifying that the DAH paddle was still physically held:

**Before — case `DIT_CLOSURE_DAH_ON`:**
```cpp
case DIT_CLOSURE_DAH_ON:
    if (dit_buffer) {
        if (dah_buffer) { dah_buffer = 0; }
        else            { last_closure = DIT_CLOSURE_DAH_OFF; }
    } else {
        if (dah_buffer) {
            last_closure = DAH_CLOSURE_DIT_OFF;  // BUG: no pin check
        } else {
            last_closure = NO_CLOSURE;
        }
    }
    break;
```

The symmetric defect exists in `DAH_CLOSURE_DIT_ON` for the case where DAH ends and `dit_buffer` is `1`.

### Fix

Before transitioning to the opposite-element state, read the physical paddle pin. If the paddle has already been released, clear the buffer and set `last_closure` to `NO_CLOSURE` instead.

**After — case `DIT_CLOSURE_DAH_ON`:**
```cpp
case DIT_CLOSURE_DAH_ON:
    if (dit_buffer) {
        if (dah_buffer) { dah_buffer = 0; }
        else            { last_closure = DIT_CLOSURE_DAH_OFF; }
    } else {
        if (dah_buffer) {
            // FIX: only queue DAH if the paddle is still physically held.
            { byte dah_pin = (configuration.paddle_mode == PADDLE_NORMAL)
                             ? paddle_right : paddle_left;
              if (paddle_pin_read(dah_pin) == LOW) {
                  last_closure = DAH_CLOSURE_DIT_OFF;
              } else {
                  dah_buffer   = 0;
                  last_closure = NO_CLOSURE;
              }
            }
        } else {
            last_closure = NO_CLOSURE;
        }
    }
    break;
```

**After — case `DAH_CLOSURE_DIT_ON` (symmetric fix):**
```cpp
case DAH_CLOSURE_DIT_ON:
    if (dah_buffer) {
        if (dit_buffer) { dit_buffer = 0; }
        else            { last_closure = DAH_CLOSURE_DIT_OFF; }
    } else {
        if (dit_buffer) {
            // FIX: only queue DIT if the paddle is still physically held.
            { byte dit_pin = (configuration.paddle_mode == PADDLE_NORMAL)
                             ? paddle_left : paddle_right;
              if (paddle_pin_read(dit_pin) == LOW) {
                  last_closure = DIT_CLOSURE_DAH_OFF;
              } else {
                  dit_buffer   = 0;
                  last_closure = NO_CLOSURE;
              }
            }
        } else {
            last_closure = NO_CLOSURE;
        }
    }
    break;
```

### Verification

All three test scenarios confirmed correct after applying both fixes:

| # | Action | Expected output | Result |
|---|---|---|---|
| 1 | Hold DAH, brief DIT, release DIT before DAH ends | `DAH–DIT` | ✅ PASS |
| 2 | Hold DAH, press DIT, release both during inter-element space | `DAH–DIT` | ✅ PASS |
| 3 | Hold DAH, press DIT, release both during DIT | `DAH–DIT` | ✅ PASS |

