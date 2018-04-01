
/////////////for hot spot
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

int Analog = A0;

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(D0, D1, D2, D3, D4, D5);

/////////////for hotspot
MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "Boom";
const char* password = "vaibhav1234";

String webString=""; 

ESP8266WebServer server(80);

String webPage = "";
String web="";
int pin1 = D7;
int pin2 = D8;

int TDS_level=0, Ec_Level=0;
void setup()
{   
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

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

  /**************************************************************************************/
  
    server.on("/TDS", "/Ec" []()
    { 
      // if you add this subdirectory to your webserver call, you get text below :)
    //  getTDS();       // read sensor
     get_TDS();...
     get_Ec ();... 
     webString="TDS: "+String((float)TDS_level)+"oC";
     webString="Ec: "+String((float)Ec_level)+"oC";
     
     server.send(200, "text/plain", webString);            // send to someones browser when asked
    });

    
  server.on("/PUMP ON", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PUMP ON ");
    delay(1000);
  });
  server.on("/PUMP OFF", []()
  {
    server.send(200, "text/html", webPage);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
     lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PUMP OFF");
    delay(1000); 
  });
  server.begin();
  Serial.println("Congats Boss, Your HTTP server started");
}

void loop() 
{
server.handleClient();
get_TDS();
get_Ec ();
delay(1000);
}

void get_TDS(), get_Ec ()
{
  int TDS_level1= analogRead(Analog);
  TDS_level=TDS_PPM;  
  Ec_level=Ec;
 }

