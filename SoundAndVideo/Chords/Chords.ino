
#include <Tone.h>    // import fancier Tone library

/*
CHORDS
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 The built-in Tone library can only make one note at a time - great
 for simple alerts and feedback but not so great for more elaborate
 instruments.
 
 This example uses the fancier Tone library; download and details here:
 http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation
 
 You may have to add the following line to the Tone.cpp file in the
 library to get it to work with Arduino 1.0: #include <Arduino.h>
 
 CHALLENGE:
 + Try attaching buttons to different Tone objects - see if you can
   make a keyboard that plays the note until the button is released.
 + Can you invent a better data structure for melodies that includes
   pitches and durations? Hint: arrays or objects?
   
 */

Tone t1, t2, t3;  // create Tone objects - one for each simultaneous pitch


void setup() {
  t1.begin(7);    // initialize all on pin 7
  t2.begin(7);    // note: this does not start the tone, just gets it ready
  t3.begin(7);
}


void loop() {

  // play a chord every 1/4-second
  if (millis() % 1000 == 0) {
    t1.play(NOTE_C4, 500);        // the optional second argument is duration in ms
    t2.play(NOTE_E5, 500);        // if not included, use t1.stop() to end the note
    t3.play(NOTE_G5, 500);
  }
}


