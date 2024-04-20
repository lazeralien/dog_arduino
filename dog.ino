int ledPin = 13; // onboard LED
int inputPin1 = A0;
const int RELAY_PIN = 3;
int counter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin1, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  int sensorVal1 = digitalRead(inputPin1);

  if (sensorVal1 == HIGH) {
      counter++;
  }
  else if (counter > 1) {
    counter--;
  }

  if (counter > 10) {
    counter = 0;
    Serial.println("On");
    digitalWrite(RELAY_PIN, HIGH);
    delay(60000); //60 seconds pump on
    Serial.println("Off");
    digitalWrite(RELAY_PIN, LOW);
    delay(10000); // 10 seconds pump off
  }

  delay(100); // Add a small delay to avoid excessive printing

}
