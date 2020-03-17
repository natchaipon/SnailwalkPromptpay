#include "SnailwalkPromptpay.h"
#include <Arduino.h>

SnailwalkPromptpay::SnailwalkPromptpay(const char* tax , float amount , const char* ssid , const char* pass)
{
    _tax = tax;
    _amount = amount;
    _ssid = ssid;
    _pass = pass;
}

void SnailwalkPromptpay::begin()
{
  WiFi.begin(_ssid , _pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}


String SnailwalkPromptpay::genThaiQR()
{
    WiFiClient client;
    HTTPClient http;
    String url = "http://103.86.49.178/thaiqr/" + String(_tax) + "/" + String(_amount);
    if (http.begin(client, url)) {  // HTTP
      int httpCode = http.GET();

      if (httpCode > 0) {
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
            StaticJsonDocument<300> doc;
            DeserializationError error = deserializeJson(doc , payload.c_str());
            String qr = doc["QRData"]["QRText"].as<String>();
            return qr;
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
}