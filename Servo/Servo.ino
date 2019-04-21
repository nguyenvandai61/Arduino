#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.write(1);  // set servo to mid-point
} 

void loop() {} 
