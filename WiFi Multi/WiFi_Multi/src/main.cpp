#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>   //  Biblioteca Inserida 
WiFiMulti wifiMulti;    //Declarando um recurso para ser utilizado

const uint32_t connectTimeoutMs = 10000;
int n;

void setup()
{
    Serial.begin(9600);
    delay(10);
    WiFi.mode(WIFI_STA);
       
    wifiMulti.addAP("Pedroso 2.4G", "pedroso2.4g"); // Inserir credenciais de nome da rede e senha 
    wifiMulti.addAP("Bruno Galaxy A71", "galaxya71"); // Inserir credenciais de nome da rede e senha 
      
    n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0)
    {
        Serial.println("no networks found");
    } 
    else
    {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) 
        {
            
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }

  
    Serial.println("Connecting Wifi...");
    if(wifiMulti.run() == WL_CONNECTED) 
    {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }
}

void loop()
{
 
  if (wifiMulti.run(connectTimeoutMs) == WL_CONNECTED)
  {
      Serial.print("WiFi connected: ");
      Serial.print(WiFi.SSID());
      Serial.print(" ");
      Serial.println(WiFi.RSSI());
  }
  else
  {
      Serial.println("WiFi not connected!");
  }
  delay(1000);
}