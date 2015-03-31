
/*
DC MOTORS
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Motors are cool, but take a bit more planning than an LED. 
 
 A FEW THINGS TO CONSIDER:
 1. Voltage: how much power does your motor require? Your Arduino can
    safely provide 5V.
    
 2. Current: how much current does your motor require? Drawing more
    than 300mA from your Arduino can cause major problems with your
    computer and/or your Arduino. The motor will draw more current 
    the more load is put on it - try stalling your motor and see the
    spike in current draw!
    
 3. Flyback: you may need a "flyback diode" to protect voltage from 
    shooting back into your Arduino when the motor stops.
 
 For an explanation of how the timing using millis() is being used,
 see 'FancierBlink' in the 'Basics' examples, or 'BlinkWithoutDelay'
 in the Arduino example sketches.
 
 For a full explanation and schematic, see this tutorial from Adafruit:
 https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors
 
 CHALLENGE:
 + Can you make a behavior happen if the two motors are both off (such as
   turn on an LED? 
   
 */

// motor 1
const int motorPin1 =   12;          // motor connected to pin 12
int interval1 =         500;         // interval for motor to go on/off
long prev1 =            0;           // store the previous time the state was changed*
boolean state1 =        false;       // current on/off state of the motor

// motor 2
const int motorPin2 =   13;
int interval2 =         750;
long prev2 =            0;
boolean state2 =        false;


// ** note we use the 'long' variable, which can hold larger numbers
//    than a standard 'int' can (used for storing times in ms, for example)


void setup() {
  pinMode(motorPin1, OUTPUT);     // motor pin to output mode
  prev1 = millis();               // set previous time to current time
  
  pinMode(motorPin2, OUTPUT);
  prev2 = millis();
}


void loop() { 

  // motor 1
  if (millis() > prev1 + interval1) {    // if enough time has passed...
    state1 = !state1;                    // make the motor state the opposite
    prev1 = millis();                    // and set previous time to current
  }  
  if (state1 == true) {                  // if state is true, turn on
    digitalWrite(motorPin1, HIGH);
  }
  else {
    digitalWrite(motorPin1, LOW);
  }

  // motor 2
  if (millis() > prev2 + interval2) {
    state2 = !state2;
    prev2 = millis();
  }
  
  // a more reusable 'function' that turns the motor
  // on and off like above
  motorOnOff(motorPin2, state2);
}


// a custom function - this for turning a motor on/off
// 'void' means no value is returned to our loop
// the two variables are called 'arguments' - here we
// pass the motor (motorPin1/motorPin2) and the current 
// state (state1/state2)

void motorOnOff(int motor, int state) {
  if (state == true) {
    digitalWrite(motor, HIGH);
  }
  else {
    digitalWrite(motor, LOW);
  }
}


