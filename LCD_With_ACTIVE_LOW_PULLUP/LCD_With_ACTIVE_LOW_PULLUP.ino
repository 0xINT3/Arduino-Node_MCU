#include<LiquidCrystal.h>

const int rs=D1, en=D2, d4=D3, d5=D4, d6=D5, d7=D6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 void setup()
 {
  lcd.begin(16,2);
  pinMode(D7,INPUT_PULLUP);
  lcd.setCursor(0,0);
  lcd.print("OBSTACLE DETECTED");
 }
 void loop()
 {
  int IR_VAL=digitalRead(D7); 
  if(IR_VAL==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("OBSTACLE: Y");
    delay(200);
    
  }
  else {
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("OBSTACLE: N");
    delay(200);
  }
 }
 

