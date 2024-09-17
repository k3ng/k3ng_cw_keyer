### Proof Of Concept Pressure Sensor Paddles using strain sensor and ADC - Arduino Nano / CS1237 ADC implementation
  (by HB9TXB)

#### Goal: 
Powerful and flexible keyer with built-in reliable iambic paddle, easily built without specialised mechanical (machining) skills.


#### Why load sensor:
- Load sensor based paddle is self calibrating, sensitivity is adjustable from command line interface separately for dot and dash.
- In order to reduce backslash,  existing mechanical paddle design utilize ball bearings. It is an overkill as angular (rotational) movement is almost non-existent.
- Mechanical contacts prone to bouncing.
- Minimal contact distance (0.1 mm) and minimal force (10 grams) difficult to maintain with mechanical paddles.
- More reliable compared to capacitive touch paddle, behaves like usual mechanical paddle.
- Sensor paddle is an order of magnitude cheaper than mechanical paddles.


#### Features:
- All [K3NG capabilities](https://github.com/k3ng/k3ng_cw_keyer/wiki) available.
- Equally suitable for beginners and experts.
- Affordable, off the shelf, load sensor and ADC components.  
  ( total approx. 10 USD CHF for two ADC and two sensors ( ADC 2x1.3 USD, sensor 2 x 2~3 USD   ))
- Boards: "compatible"  Nano board  1.8 CHF  ;   "compatible" ESP32 approx. 3-4 USD 
- Can be developed as add-on to existing K3NG kits.

#### Two Prototypes:
1) Implementation [based on ESP32 based k3ng keyer - SP5IOU](https://github.com/djbr1/K3NG-Arduino-Keyer-ESP32_PlatformIO)  has OLED SSD1306 display and command line interface over Bluetooth, allowing parameter change from [Android Bluetooth Seria Terminal ](https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal) or  [Web Serial ](https://github.com/ok1cdj/K3NG-keyer-serial-terminal) (using Chrome) . Uses Hx711 ADC.
  
2. [Arduino nano implementation](https://github.com/djbr1/k3ng_cw_keyer), allows parameter change through USB interface using [Android Serial Terminal app](https://play.google.com/store/apps/details?id=de.kai_morich.serial_usb_terminal) or  [Web Serial ](https://github.com/ok1cdj/K3NG-keyer-serial-terminal) (using Chrome) . [CS1237 ADC](https://github.com/tremaru/iarduino_ADC_CS1237) is used.  
    [**Schematic diagram**](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/k3ng_keyer_nano_cs1237.sch_2024-09-17.pdf) (based on OK1CDJ nano keyer implementation)
   


#### TODO:    
 - PCB design
 - BoM for additional components
 - physical buttons as required
  - optocouplers and 3.5 mm jacks for PPT and TX line
 - RFI/EMI shielding
 - "paddle only" output if transceiver builtin keyer is preferred

 <br/><br/>
 #### Pictures and videos
[Youtube video showing paddle sensitivity](https://www.youtube.com/watch?v=UNnNl10UAn8)
[![Sensitivity demo](https://img.youtube.com/vi/UNnNl10UAn8/0.jpg)](https://www.youtube.com/watch?v=UNnNl10UAn8)

[//]: 
  https://www.youtube.com/watch?v=UNnNl10UAn8

![](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/k3ng_keyer_nano_cs1237.sch_2024-09-17.png?raw=true)


![](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/IMG_1330.JPG?raw=true)
![](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/IMG_1329.JPG?raw=true)
![](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/IMG_1344.JPG?raw=true)
![](https://github.com/djbr1/k3ng_cw_keyer/blob/master/k3ng_keyer/ADC_CS1237/Screenshot_2024-09-17_at_18.34.58.jpg?raw=true)



