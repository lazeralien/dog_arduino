// Using a PIR sensor


#include <Wire.h>
const int RELAY_PIN = 3; // Change this to match your relay pin

int ledPin = 13;             // choose the pin for the LED
int inputPin = 2;            // choose the input pin (for PIR sensor)
int pirState = LOW;          // we start, assuming no motion detected
int val = 0;                 // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(inputPin, INPUT);  // declare sensor as input
  pinMode(RELAY_PIN, OUTPUT); // declare relay pin as output

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin); // read input value
  if (val == HIGH) {           // check if the input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    digitalWrite(RELAY_PIN, HIGH);
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    digitalWrite(RELAY_PIN, LOW);
    if (pirState == HIGH){
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
