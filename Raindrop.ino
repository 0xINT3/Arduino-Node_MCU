#include <ESP8266WiFi.h>
#include <Wire.h>

int nRainIn = A0;
int nRainDigitalIn = 2;
int nRainVal;
boolean bIsRaining = false;
String strRaining;

String apiKey = "5T49MWF9ZZ19GILJ";
const char* ssid = "gaurav";
const char* password = "12345678";

const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
}
  
  void loop() {
    nRainVal = analogRead(nRainIn);
    bIsRaining = !(digitalRead(nRainDigitalIn));

    
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(nRainVal);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);

    if (bIsRaining) {
      strRaining = "YES";
    }
    else {
      strRaining = "NO";
    }

    Serial.print("Raining?: ");
    Serial.print(strRaining);
    Serial.print("\t Moisture Level: ");
    Serial.println(nRainVal);

    delay(200);

  }
  }
