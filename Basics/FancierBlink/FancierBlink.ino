
/*
FANCIER BLINK
Jeff Thompson | 2013 | www.jeffreythompson.org

Adding to our initial 'Blink' sketch, we do some math and if/then
statements for more interesting functionality.

Schematic (or use built-in LED on the board and do nothing!):
+ Long leg in digital pin 13
+ Short led in ground pin next to 13

CHALLENGE:
+ Can you make this system count? What about something more complex like
  a Fibonnoci sequence (http://en.wikipedia.org/wiki/Fibonacci_number)?

*/

int ledPin =    13;       // LED connected on digital pin 13
int delayTime = 50;       // variable for delay time

// NOTE: 'delayTime' is a variable so we can update it as the program runs!


void setup() {
  pinMode(ledPin, OUTPUT);       // set LED pin (13) to output
}


void loop() {
  
  // blink on and off
  digitalWrite(ledPin, HIGH);    // on
  delay(delayTime);
  digitalWrite(ledPin, LOW);     // off
  delay(delayTime);
  
  // check if the delay time is less than 1/2 second...
  // if so, add 50ms to the time and continue
  if (delayTime < 500) {
    delayTime = delayTime + 50;  
    
    // could also use the shorter delayTime += 50, which is the same thing!
  }
  
  // otherwise (meaning the time is MORE than 1/2 second), reset to 50ms
  else {
    delayTime = 50;
  }
  
  // start again at the top of 'loop', continuing through!
}


