#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <LiquidCrystal.h>

const int rs = D1, en = D2, d4 = D3, d5 =D4, d6 =D5, d7 = D6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int outputpin= 0;
MDNSResponder mdns;

const char* ssid = "ESPServer_RAJ";
const char*  password = "RAJ@12345";
String webString=""; 

ESP8266WebServer server(80);

String webPage = "";
String web="";
int pin1 = D7;

void setup(void)
{
  webPage +="<h1><p align ='center'>ESP8266 Wifi Controlled RELAY</h1> </p>"; 
  webPage += "<h1><p align ='center'>RELAY <a href=\"RELAYON\"><button>RELAYon</button></a>&nbsp;<a href=\"RELAYOFF\"><button>RELAYoff</button></h1></a></p>";
    
  // preparing GPIOs
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, LOW);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  lcd.begin(16, 2);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) 
  {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", []()
  {
    server.send(200, "text/html", webPage);
  });

  server.on("/RELAYON", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(pin1, HIGH);
    lcd.setCursor(0,1);
    lcd.print("LED_ONN");
    delay(500);
  });
  
  server.on("/RELAYOFF", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(pin1, LOW);
    lcd.setCursor(0,1);
    lcd.print("LED_OFF");
    delay(500); 
  });
  
   
  server.begin();
  Serial.println("http server started...");
}
 
void loop(void)
{
  server.handleClient();
} 


