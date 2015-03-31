
/*
FADE LED
Jeff Thompson | 2013 | www.jeffreythompson.org

Simple on/off works well for many applications, but the Arduino lets us use Pulse Width
Modulation (PWM) to get intervals between all the way on and all the way off.

Available only on digital pins 3,5,6,9,10,11,13 on the Uno/Leonardo, marked with '~'

Note that PWM isn't actually analog and doesn't actually fade at all!  Instead, underlying
software blinks the pin on/off very fast - the interval of the blinking appears to the human
eye to be variable, just like a flipbook appears like continuous movement!

CHALLENGE:
+ Can you make this action only occur when a button is pressed?
+ Can you count button presses, making the LED brighter each time and resetting when you hit 255?

*/

int ledPin =     9;           // LED connected to pin 9 (external LED is best for this example)
int brightness = 0;           // brightness of LED from 0-255
int amount =     5;           // amount to inc/dec brightness each step


void setup() {
  pinMode(ledPin, OUTPUT);    // set as output, just like 'digitalWrite'
}


void loop() {
  
  // increment brightness (when 'amount' is negative, this is the same as subtracting)
  // NOTE: we could also use the shorter += method
  brightness = brightness + amount;
  
  // if the brightness value passes 0 or 255 (our max range) reverse 
  // the direction and dim/brighten
  if (brightness <= 0 || brightness >= 255) {
    amount *= -1;
  }
  
  // write brightness to the LED with 'analogWrite' using PWM
  // then wait so we can see the results
  analogWrite(ledPin, brightness);
  delay(30);
}


