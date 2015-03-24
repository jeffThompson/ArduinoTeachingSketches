
#include <CapacitiveSensor.h>

/*
CAPACITIVE TOUCH SENSOR
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Buttons are cool, but touch interfaces are cooler! This *very*
 sensitive sensor is a button made from copper tape and two resistors.
 
 Requires the CapSense library:
 www.playground.arduino.cc//Main/CapacitiveSensor?from=Main.CapSense
 
 Note the older version of this library will work with this sketch,
 but will require a small modification
 
 Copper tape is available from a variety of sources, including:
 www.jameco.com/webapp/wcs/stores/servlet/ProductDisplay?storeId=
 10001&langId=-1&catalogId=10001&productId=1643551
 
 */

int threshold =       300;                       // value at which the button is considered pressed/on
int interval =        200;                       // number of reading the CapSense averages

boolean buttonState = false;                     // on/off button state
boolean prevState =   false;                     // previous (for sensing edge)

CapacitiveSensor cs = CapacitiveSensor(11,10);   // 1k protection resistor on pin 11, 10M sensing resistor on pin 10
int ledPin =          13;                        // led connected from pin 13 to ground (or internal led)


void setup() {
  pinMode(ledPin, OUTPUT);       // set led pin to output
}

void loop() {

  // read touch sensor
  long val =  cs.capacitiveSensor(interval);

  // if above the threshold, set as on; if not, set as off
  if (val >= threshold) {
    buttonState = true;
  }
  else {
    buttonState = false;
  }

  // set led high or low if the state of the button has changed
  // we don't just do this every time, as it would cause flickering
  if (buttonState != prevState) {        // if different....
    if (buttonState == true) {           // and true...
      digitalWrite(ledPin, HIGH);        // set high/on
    }
    else {                               // ditto low
      digitalWrite(ledPin, LOW);
    }      
    prevState = buttonState;             // reset for next press
  }
}


