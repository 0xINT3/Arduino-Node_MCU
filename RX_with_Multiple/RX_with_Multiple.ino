#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {

  Serial.begin(9600);
    lcd.begin(16,2);
 
 }
 void loop()
 {
  if(Serial.available()<1)
  return;
  char R=Serial.read();
  if(R!='\r')
  return;
  int POT_VAL=Serial.parseInt();
  int IR_VAL=Serial.parseInt();
  lcd.setCursor(0,0);
  lcd.print(POT_VAL);
  lcd.setCursor(0,1);
  lcd.print(IR_VAL);
 }
 
