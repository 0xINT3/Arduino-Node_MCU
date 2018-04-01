#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {
  lcd.begin(16,2);
  pinMode(D7,INPUT_PULLUP);
  Serial.begin(9600);
 }
 void loop()
 {
  int IR_VAL=digitalRead(D7); 
  if(IR_VAL==LOW)
  {
    Serial.print(10);
    lcd.print(3);
    delay(50);  
  }
  else
  {
    lcd.clear();
    Serial.print(20);
    lcd.print(4);
    delay(50);
  }
 }
  
