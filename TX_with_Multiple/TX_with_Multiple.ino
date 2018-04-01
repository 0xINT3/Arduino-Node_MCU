#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {
  int begin(16,2);
  Serial.begin(9600);
  
 }
 void loop()
 {
  int IR_VAL=digitalRead(D7);
  int POT_VAL1=analogRead(A0);
  int POT_VAL=POT_VAL1/10;
  
  if(IR_VAL1==LOW)
  {
    lcd.setCursor(0,0);
    lcd.print(POT_VAL);
    lcd.setCursor(0,1);
    lcd.print(40);

    Serial.print('\r');
    Serial.print(POT_VAL);
    Serial.print('|');
    Serial.print(40);
    Serial.print('\n');
    delay(50);
     
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print(POT_VAL);
    lcd.setCursor(0,1);
    lcd.print(50);
    Serial.print('\r');
    Serial.print(40);
    lcd.print(POT_VAL);
    Serial.print('|');
    Serial.print(50);
    Serial.print('\n');
    delay(50);
  }
 
  
