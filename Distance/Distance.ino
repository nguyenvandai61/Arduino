
/* Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input


  lcd.init();
  lcd.backlight();


  Serial.begin(9600); // Starts the serial communication


}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Khoang Cach");

  lcd.setCursor(2, 1);
  lcd.print("Cm: ");


  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor

  Serial.print("Distance: ");
  Serial.println(distance);
  lcd.setCursor(6, 1);
  lcd.print(distance);
  delay(500);
}
