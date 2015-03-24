
/*
BLINK
Jeff Thompson | 2013 | www.jeffreythompson.org

Our first program - blinking an LED!  This is the canonical
Arduino first-sketch, the equivelant of "Hello World".

Schematic (or use built-in LED on the board and do nothing!):
+ Long leg in digital pin 13
+ Short led in ground pin next to 13

CHALLENGE:
+ Can you make the behavior more complex?
+ How might you encode a message, such as Morse Code?

*/

// VARIABLES
// these are optional, but allow faster, more powerful
// changes to your code (as we will see momentarily)
int ledPin =  13;      // define the LED as on pin 13
int timeOn =  250;     // time for the LED to be on (measured in milliseconds, or ms)
int timeOff = 250;     // ditto off; 1000ms = 1 second, 500ms = 1/2 sec, etc


// SETUP
// this is code run once when your Arduino reboots - here we set the mode
// for the digital pin to output (to light up the LED)
void setup() {
  pinMode(ledPin, OUTPUT);    // arguments (or parameters) are the pin # and mode
}


// LOOP
// loop runs over and over as fast as possible until the Arduino is turned
// off or reset
void loop() {
  digitalWrite(ledPin, HIGH);    // set the LED to high (on)
  delay(timeOn);                 // pause everything for specified amount of time*
  digitalWrite(ledPin, LOW);     // turn LED off...
  delay(timeOff);                // and pause again
}

// * NOTE: when in 'delay', the Arduino completely stops all processes

