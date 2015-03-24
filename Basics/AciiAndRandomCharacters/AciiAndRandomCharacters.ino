
/*
ASCII AND RANDOM CHARACTERS
Jeff Thompson | 2013 | www.jeffreythompson.org

Expanding on the 'SerialCommunication' example, here we leverage the ASCII encoding
standard to generate random characters.

ASCII is the standard encoding for characters, each with its own number ('A' = 65, 
'z' = 122, etc).  You can read more about ASCII here:
http://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters

In programming, a single typographical symbol is called a 'char', short for 'character'. They
are, under the hood, a number which happens to be the ASCII value!  This means we can
seamlessly convert between int and char.

Since ASCII values are really just numbers, we can get a random number using the built-in
'random' function, then get the character that corresponds to that value!

CHALLENGE:
+ Expand the system to also create random spaces and line-breaks
+ Apply rules to the system: a space after each period, a space before
  a capital letter
+ Look for certain combinations of letters forming words - do something
  when they appear at random

*/

int buttonPin =   2;
int buttonState = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);            // send via USB
}


void loop() {
  
  buttonState = digitalRead(buttonPin);    // read button
  
  if (buttonState == HIGH) {              // when button is pressed, send a random character
    char c = random(65, 123);             // generate random char(acter) - two #s are low/high range
    Serial.print(c);                      // print the character without line-breaks
    delay(1);
  }
}


