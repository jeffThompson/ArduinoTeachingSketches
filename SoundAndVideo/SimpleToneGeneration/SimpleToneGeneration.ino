
/*
SIMPLE TONE GENERATION
Jeff Thompson | 2013 | www.jeffreythompson.org

Create a tone sweep from high to low using digitalWrite and
delay (here measured in microseconds rather than milliseconds).

Essentially we are creating square-waves (think NES games) - they
don't sound great but use very little resources on your
Arduino!

Too loud? Wire a potentiometer between the digital pin and your
speaker (L or R to the pin, center to your speaker) to act as
a volume knob.

CHALLENGE:
+ Can you pre-program some pitches to play a melody?

*/

int speakerPin = 7;        // digital pin for speaker
int maxDelay =   7000;     // max (lowest) frequency
int delayTime =  1;        // variable to keep track of tone frequency


void setup() {
  pinMode(speakerPin, OUTPUT);       // set to output (not PWM)
}


void loop() {
  digitalWrite(speakerPin, HIGH);    // create tone by pulsing high/low
  delayMicroseconds(delayTime);      // delay in microseconds (1,000,000/second)
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(delayTime);
  
  delayTime += 3;                    // update delay time
  if (delayTime > maxDelay) {        // reset when at the max
    delayTime = 1;
  }
}


