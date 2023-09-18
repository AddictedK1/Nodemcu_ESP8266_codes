#include<ESP8266WiFi.h>

void setup()  {
  WiFi.begin("kaushal's phone", "987654321");    
  Serial.begin(9600);
  while(WiFi.status() != WL_CONNECTED)  {
      Serial.println("scanning for wifi......");
      delay(1000);
    }
  Serial.print("connected.");
  Serial.print(WiFi.localIP());
}

void loop()  {
  
  
  
  
}
