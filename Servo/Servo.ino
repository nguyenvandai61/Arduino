#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.write(50);  // set servo to mid-point
} 

void loop() {} 
