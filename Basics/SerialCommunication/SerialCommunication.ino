
/*
SERIAL COMMUNICATION
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 One of the great things about the Arduino is that it can talk to your computer!  Communicating
 over USB is called "serial communication", allowing us to send values from the Arduino to the
 computer (sensor readings) and back to the Arduino (mouse input, parsed web page, etc).
 
 In order to see the results, you must open the Serial Monitor in the Arduino IDE.
 
 A FEW DRAWBACKS TO CONSIDER:
 + Notice how holding down your button can cause multiple "bangs" to be sent? To avoid
   this, we need slightly more complex code - see the 'Debounce' and 'ButtonStateChange'
   examples for ideas on how to solve this.
 
 CHALLENGE:
 + Can you make this system print the alphabet in order, starting over at 'A' when 'Z' is reached?
 + Can you build a maze that a cursor traverses with digital buttons, using the SerialMonitor as
   the display?
 
 */

int buttonPin =   2;
int buttonState = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  
  // start connection over USB; 96000 is the 'baud rate', or bits/second
  Serial.begin(9600);
}


void loop() {

  buttonState = digitalRead(buttonPin);     // read button as in previous examples!

  if (buttonState == HIGH) {
    Serial.println("BANG!");                // send a new line with the word "bang"
    delay(1);                               // waiting 1ms improves stability of your program

    // NOTE: if we want to combine values (like a label & sensor reading), we must use the 'print'
    // command several times (we can't combine items like Java, Python, etc)
    
    Serial.print("Button: ");      // a label for the data (great when you have sensor multiple readings)
    Serial.print(buttonState);     // the button's state
    Serial.print("\n");            // a 'newline' character - otherwise our data all piles up on itself!
  }
}


