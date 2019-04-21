#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
//0x27 là d?a ch? màn hình trong bus I2C. Ph?n này chúng ta không c?n ph?i quá b?n tâm vì h?u h?t màn hình (20x4,...) d?u nhu th? này!
//16 là s? c?t c?a màn hình (n?u dùng lo?i màn hình 20x4) thì thay b?ng 20
//2 là s? dòng c?a màn hình (n?u dùng lo?i màn hình 20x4) thì thay b?ng 4

void setup() {
  lcd.init();       //Kh?i d?ng màn hình. B?t d?u cho phép Arduino s? d?ng màn hình, cung gi?ng nhu dht.begin() trong chuong trình trên
  
  lcd.backlight();   //B?t dèn n?n
  lcd.print("Hello world");  //Xu?t ra ch? Hello world, m?c d?nh sau khi init thì con tr? t?i c?t 0 hàng 0 (trong C, khác v?i quy u?c c?a ti?ng Vi?t, m?i ch? s? d?u b?t d?u b?ng s? 0, vì v?y b?n c?n hi?u r?ng, n?u ta k? m?t b?ng có 2 hàng và 16 c?t thì ô góc trên cùng bên trái là ô (0,0) tuong t? v?i các ô khác, ta c? tang d?n giá tr? lên!
  lcd.setCursor(0,1); //Ðua con tr? t?i hàng 1, c?t 0
  lcd.print("I love Arduino !");// B?n th?y trên màn hình r?i ch??
}

void loop() {
}
