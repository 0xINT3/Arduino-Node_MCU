int RELAY1_PIN=D1;
int RELAY2_PIN=D2;
void setup() 
{
  
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
}

void loop() 
{
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, LOW);
  delay(5000);                       
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, HIGH);
  delay(5000);                       
 }
