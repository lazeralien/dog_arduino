#include <Wire.h>
const int RELAY_PIN = 3;

int ledPin = 13;
int inputPin = 2;
int pirState = LOW;
int val = 0;   //pin status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);  // declare PIR sensor
  pinMode(RELAY_PIN, OUTPUT); // declare relay for pump

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin); // read input value
  if (val == HIGH) {           // check if the input is HIGH
    digitalWrite(ledPin, HIGH);
    digitalWrite(RELAY_PIN, HIGH);
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    digitalWrite(RELAY_PIN, LOW);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
