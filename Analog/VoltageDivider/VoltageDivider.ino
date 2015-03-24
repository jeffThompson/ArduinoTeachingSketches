
/*
VOLTAGE DIVIDER
Jeff Thompson | 2013 | www.jeffreythompson.org

While a potentiometer doesn't require any other components, other analog
sensors (like light sensors, etc) require a circuit called a voltage
divider.  Here we use a simple analog sensor (such as a Light-Dependent-
Resistor) to control the brightness
of an LED!

The basic formula (http://en.wikipedia.org/wiki/Voltage_divider):
Vout = (R2/(R1+R2)) * Vin

Or, converted to a format that's more suitable for us:
R2 = R1 / ((Vin/Vout)-1)

If our sensor's output should be a range of 0-4.5V (nearly 5V) and
our sensor's max resistance is 10Kohm:
R2 = 10,000 / ((5/4.5)-1) = 10,000/0.1111 = 90Kohm

So, our diagram is:
+5V --- 10k sensor --+--- ~90k resistor --- GND
                     |
                    A 0

MORE INFO:
For a great explanation of the voltage divider, 
see: http://www.sparkfun.com/tutorials/207

CHALLENGE:
+ Use a multimeter to find the min/max range for your other sensors;
  calculate the necessary resistor to make an optimal voltage divider.
  
*/

int sensorPin =   A0;         // read sensor on analog pin 0
int sensorValue = 0;          // variable to read sensor
int ledPin =      11;         // LED for output


void setup() {
  pinMode(ledPin, OUTPUT);    // LED to output!
  Serial.begin(9600);         // display values over USB
}


void loop() {
  
  // read sensor as usual (returns a value from 0-1023)
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
    
  // use 'map' to convert from range 0-1023 to range 0-255
  // arguments are variable, input low,high, output low,high
  sensorValue = map(sensorValue, 0,1023, 0,255);
  
  // NOTE: you can also 'tune' your map's values to the 'real' readings
  // from your sensor - for example, if your sensor actually reads
  // 400 for the low and 800 for the high, change your function to:
  // sensorValue = map(sensorValue, 400,800, 0,255);
  
  // then, make sure that our values NEVER go above 255 or below 0
  sensorValue = constrain(sensorValue, 0, 255);
    
  // use PWM to output sensor reading to LED!
  analogWrite(ledPin, sensorValue);
  
  // make sure we don't overload the serial connection
  delay(1);
}


