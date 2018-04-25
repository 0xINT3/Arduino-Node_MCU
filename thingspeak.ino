#include <ESP8266WiFi.h>
#include <Wire.h>

// replace with your channel's thingspeak API key,
String apiKey = "*******";
const char* ssid = "******";
const char* password = "******";

const char* server = "api.thingspeak.com";
int WET = 16; // Wet Indicator at Digital PIN D0
int DRY = 2; // Dry Indicator at Digital PIN D4

int sense_Pin = 0; // Soil Sensor input at Analog PIN A0
int value = 0;


WiFiClient client;
void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);

  delay(10);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.begin(9600);
  pinMode(WET, OUTPUT);
  pinMode(DRY, OUTPUT);
  delay(2000);
}


void loop() {
  Serial.print("MOISTURE LEVEL : ");
  value = analogRead(sense_Pin);
  Serial.println(value);
  if (value < 500)
  {
    digitalWrite(WET, HIGH);
  }
  else
  {
    digitalWrite(DRY, HIGH);
  }
  delay(1000);
  digitalWrite(WET, LOW);
  digitalWrite(DRY, LOW);

  int temp = analogRead(A0);
    if (client.connect(server, 80)) {
      String postStr = apiKey;
      postStr += "&field1=";
      postStr += String("temp");
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);



      Serial.print("Moisture Sensor Value: ");
      Serial.print(temp);

      Serial.println("\nSending data to ThingSpeak");
      delay(1000);

  }
  client.stop();


  Serial.println("Waiting...");

}
