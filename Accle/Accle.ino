#include <LiquidCrystal_I2C.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>
Servo s;
MPU6050 mpu6050(Wire);
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  s.attach(2);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.println(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());
  
  lcd.setCursor(0, 0);
  lcd.print(round(mpu6050.getAngleY()+90));
  s.write(round(mpu6050.getAngleY()+90));

  delay(200);
  lcd.clear();
}
