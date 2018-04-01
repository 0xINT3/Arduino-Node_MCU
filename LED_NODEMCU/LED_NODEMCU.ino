int LED_PIN=D1;
void setup() 
{
  
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LED_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_PIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
