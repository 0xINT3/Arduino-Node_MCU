#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {
  lcd.begin(16,2);
  lcd.print("UPES");
 }
 void loop()
 {
  lcd.setCursor(0,1);
  lcd.print("PST PROGRAM");
 }

