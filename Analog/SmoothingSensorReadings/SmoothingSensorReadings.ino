
/*
SMOOTHING SENSORS
Jeff Thompson | 2013 | wwww.jeffreythompson.org

Analog sensors (and electronics in general) are messy!  They often behave erratically and
inconsistently from reading to reading.  We can make this process better by keeping a
running average of the past N sensor readings, dropping the oldest reading and adding a new
one. While our sensor will be less responsive, it will also be more stable!

This sketch is meant to be a little more readable than the Arduino example "Smoothing", though
that example will have considerably better performance.

** FOR LOOPS:
A very powerful (but sometimes confusing) construct, 'for' loops iterate over a range of values;
this is useful for going through a list (like this example) or doing things like initializing
lots of input/output pins.

The basic structure:
for (initial value; test condition; increment) {
for (int index=0; index<numValues; index++) {
  // do something here!  we can access the value 'index' as needed
}

The variable 'index' starts at 0, and is tested each loop.  If it is less than the # of
values (the max of the loop), add one to it and execute some code.  If it is now >= to 
the max for the loop, break out and continue with the program!

*/

const int sensorPin =   A0;      // read sensor on analog pin 0
const int numReadings = 10;      // how many readings to average

int total =          0;          // keep a running total to average
int averageReading = 0;          // average sensor value
int index =          0;          // current position in the 'readings' list
int readings[numReadings];       // a list (called an 'array') of the past N readings


void setup() {
  Serial.begin(9600);                        // start communication via USB
  
  // start the list of readings at all 0
  for (int i=0; i<numReadings; i++) {        // here we use a 'for loop'** - powerful but sometimes confusing!
    readings[i] = 0;                         // access each value in the array by it's index (i) and set to 0
  }
}


void loop() {
  
  // add a new reading to our list - do this at the 'index' position,
  // then update the index so we walk through the list
  readings[index] = analogRead(sensorPin);    // we get/change a value in the list by specifying a location
  index++;                                    // remember that ++ means to add 1 to the variable
  
  // if the index is now out of the range of our list, reset it to 0
  if (index >= numReadings) {
    index = 0;
  }
  
  // count up the items in the list, then figure out the average and print
  // it to the screen via USB
  total = 0;
  for (int i=0; i<numReadings; i++) {      // for loop again!
    total += readings[i];                  // add up the results
  }
  averageReading = total / numReadings;
  Serial.println(averageReading);
  
  // a slight delay will improve our program's stability
  delay(1);
}


