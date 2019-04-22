#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#define IN1  7
#define IN2 6
#define IN3 5
#define IN4 4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
 
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255 - speed);
}
 
void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);// chân này không có PWM
}
 
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);//đảm báo giá trị nằm trong một khoảng từ 0 - MAX_SPEED - http://arduino.vn/reference/constrain
  analogWrite(IN4, 255 - speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
}
 
void loop()
{
  // NGUOC CHIEU
  lcd.print("motor 1: ");
  lcd.setCursor(11,0);
  lcd.print(MAX_SPEED);
  lcd.setCursor(0,1);
  lcd.print("Motor 2: -");
  lcd.setCursor(12,1);
  lcd.print(MAX_SPEED);
  
  motor_1_Tien(MAX_SPEED); // motor 1 tiến
  motor_2_Lui(MAX_SPEED); //motor 2 lùi
  delay(5000);
  lcd.clear();

  
  motor_1_Dung();
  motor_2_Dung();
  lcd.print("motor 1: ");
  lcd.setCursor(11,0);
  lcd.print(0);
  lcd.setCursor(0,1);
  lcd.print("Motor 2: ");
  lcd.setCursor(11,1);
  lcd.print(0);
  
  delay(10000);//dừng 10s
  
  lcd.clear();
  //Cung chieu: 
  lcd.print("motor 1: ");
  lcd.setCursor(11,0);
  lcd.print(MAX_SPEED);
  lcd.setCursor(0,1);
  lcd.print("Motor 2: ");
  lcd.setCursor(11,1);
  lcd.print(MAX_SPEED);
  
  motor_1_Tien(MAX_SPEED); // motor 1 tiến
  motor_2_Tien(MAX_SPEED); //motor 2 lùi
  delay(5000);
  lcd.clear();
  
  motor_1_Dung();
  motor_2_Dung();
  lcd.print("motor 1: ");
  lcd.setCursor(11,0);
  lcd.print(0);
  lcd.setCursor(0,1);
  lcd.print("Motor 2: ");
  lcd.setCursor(11,1);
  lcd.print(0);
  delay(10000);//dừng 10s
  lcd.clear();
}
