
/*
USING THE TONE LIBRARY
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 Simple tone output (as of Arduino 1.0) is now built in
 and requires no external libraries. You are limited to
 one tone at a time - for a fancier version, see the "Chords"
 sketch in this section.
 
 To more easily create note values, we also import a file called
 "pitches.h" so we can ask for the notes by name. 
 
 */

// import a file called pitches.h (see tab for details)
#include "pitches.h"


void setup() {
  // nothing here!
}


void loop() {
  if (millis() % 500 == 0) {    // make a note every 500ms
    tone(7, NOTE_C4, 250);      // on pin 7, generate C4 for 250 ms
  }
}


