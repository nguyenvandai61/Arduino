#include <Servo.h>
#include<Wire.h>
#include <LiquidCrystal_I2C.h>

Servo servo_test;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
int x, y, z;
int minVal = 265;
int maxVal = 402;


void setup() {
  Wire.begin(); 
  Wire.beginTransmission(MPU_addr); 
  Wire.write(0x6B); Wire.write(0); 
  Wire.endTransmission(true); 

  servo_test.attach(9);

    lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  
  Serial.begin(9600);
} void loop() {
  Wire.beginTransmission(MPU_addr); 
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true); 

  // Doc cac gia tri gia toc
  AcX = Wire.read() << 8 | Wire.read(); 
  AcY = Wire.read() << 8 | Wire.read(); 
  AcZ = Wire.read() << 8 | Wire.read();
//  GyX = Wire.read() << 8 | Wire.read();
//  GyY = Wire.read() << 8 | Wire.read();
//  GyZ = Wire.read() << 8 | Wire.read();


  int xAng = map(AcX, minVal, maxVal, -90, 90);
  int yAng = map(AcY, minVal, maxVal, -90, 90);
  int zAng = map(AcZ, minVal, maxVal, -90, 90);

  // Chuyen sang do deg
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  servo_test.write(y);
  
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);
  
  Serial.print("AngleX= "); Serial.println(x);

  Serial.print("AngleY= "); Serial.println(y);

  Serial.print("AngleZ= "); Serial.println(z);
  Serial.println("-----------------------------------------");
  lcd.setCursor(1,0);
  lcd.print("X: ");
  lcd.print(x);
  lcd.print("Y: ");
  lcd.print(y);
  lcd.print("Z: ");
  lcd.print(z);

  lcd.setCursor(2,1);
  lcd.print("Quay Y");


//  Serial.print("Gyroscope: ");
//  Serial.print("X = "); Serial.print(GyX);
//  Serial.print(" | Y = "); Serial.print(GyY);
//  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");




  delay(100);
}
