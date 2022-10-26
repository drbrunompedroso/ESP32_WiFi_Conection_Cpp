#include <Arduino.h>
#include <WiFi.h>
#define LED 2  

const char *ssid = "xxxxxx";   // usuário (Roteador)
const char *password = "xxxxxx";   // senha (roteador)

void setup() 
{  
  Serial.begin(9600);
  delay(20);

  pinMode(LED, OUTPUT);
  digitalWrite(LED,LOW);

  Serial.println();
  Serial.println();
  Serial.println("Conectando ao roteador ...");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
  Serial.println(" ");
  Serial.println("Rede Wifi Conectada");
  Serial.println("IP de acesso: ");
  Serial.println(WiFi.localIP());
}
void loop()
{
  if(WiFi.status() == WL_CONNECTED) digitalWrite(LED, HIGH);
}
    