
const int analogPin = A0;   // Cong bien tro
const int ledCount = 10;    // So den led

int ledPins[] = {
  3, 4, 5, 6, 7, 8, 9, 10, 11, 12
};   // Cac cong led


void setup() {
  // Tung cong den led la cong OUTPUT:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // Doc gia tri cua bien tro:
  int sensorReading = analogRead(analogPin);
  // Chan A0 co gia tri trong khoang 0 -> 1023, ta anh xa sang
  // 0 -> so den led:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // Neu led < ledLevel thi bat led
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
