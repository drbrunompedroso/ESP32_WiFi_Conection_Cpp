#include <Arduino.h>
#include <WiFi.h>
#define LED_INT 2 
#define LED_EXT 13  


const char *ssid = "xxxxxx";   // usuário (Roteador)
const char *password = "xxxxx";   // senha (roteador)

void setup() 
{
  
    Serial.begin(9600);
    delay(20);

    pinMode(LED_INT, OUTPUT);
    pinMode(LED_EXT, OUTPUT);
    digitalWrite(LED_INT,LOW);
    digitalWrite(LED_EXT,LOW);

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
  if(WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(LED_INT, LOW);
    digitalWrite(LED_EXT, HIGH);

  } 
  else if(WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_INT, HIGH);
    digitalWrite(LED_EXT, LOW);
  }
}
    