
/*
 VHS TAPE SENSOR
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 A piece of VHS tape makes a great analog sensor! The non-reflective surface
 works like a resistor, so running +5V into one end and GND into the other,
 a wire into an analog pin will return a variable resistance and therefore
 voltage!
 
 Also: graphite pencil works great too - draw a heavy circuit on a piece of
 paper and hook it up using alligator clips.
 
 CHALLENGE:
 + Can you think of any other materials that are resistive? No? Get out your
 multimeter and find some!
 
 */

int vhsPin =     A0;      // pin to read from tape
int vhsReading = 0;       // variable to store reading
int ledPin =     11;      // LED output to display the result

void setup() {
  pinMode(ledPin, OUTPUT);    // LED to output
  Serial.begin(9600);         // serial so we can see the result over USB
}

void loop() {

  // read the VHS tape, convert to useable range
  vhsReading = analogRead(vhsPin);
  vhsReading = map(vhsReading, 0, 1024, 0,255);   // map input to PWM range
  vhsReading = constrain(vhsReading, 0, 255);     // make sure we don't go over 255 or under 0

  // display and write result over USB
  analogWrite(ledPin, vhsReading);
  Serial.println(vhsReading);
  delay(10);
}


