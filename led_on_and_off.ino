#include<ESP8266WiFi.h>

#define led D7

WiFiClient client01;
WiFiServer server(80);  //port number where the server listens to...

void setup()  {
  Serial.begin(9600);
  WiFi.begin("kaushal's phone", "987654321");
  pinMode(led, OUTPUT);
  while(WiFi.status() != WL_CONNECTED)  {
    Serial.println("scanning for wifi.... ");
    delay(1500);
    }  
    Serial.print("connected.");    
    Serial.print(WiFi.localIP());
    server.begin();
}

void loop()  {
  client01 = server.available();
  String request;  
    if(client01 == 1)  {
      request = client01.readStringUntil('\n');
      Serial.println(request);
      request.trim();
      }
    if(request == "GET /ledon HTTP/1.1")  {
        digitalWrite(led, HIGH);
      }
    if(request == "GET /ledoff HTTP/1.1")  {
        digitalWrite(led, LOW);
      }
}
