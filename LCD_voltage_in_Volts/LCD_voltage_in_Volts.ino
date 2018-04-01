#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {
  lcd.begin(16,2);
 }
 void loop()
 {
  lcd.clear(); 
  int POT_VAL=analogRead(A0);
  float Voltage=((POT_VAL*(4.88)/1000));
  lcd.setCursor(0,0);
  lcd.print("POT LEVEL:");
  lcd.setCursor(0,1);
  lcd.print(Voltage);
  lcd.setCursor(6,1);
  lcd.print("VOLT");
  delay(100);
  }
 

