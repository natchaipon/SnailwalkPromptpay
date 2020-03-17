#ifndef SnailwalkPromptpay_h
#define SnailwalkPromptpay_h

#include "Arduino.h"
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class SnailwalkPromptpay
{
  public:
    SnailwalkPromptpay(const char* tax , float amount , const char* ssid , const char* pass);
    void begin();
    String genThaiQR();

  private:
    const char* _tax;
    float _amount;
    const char* _ssid;
    const char* _pass;
};

#endif