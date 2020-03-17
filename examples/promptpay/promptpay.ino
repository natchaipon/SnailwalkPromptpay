#include <SnailwalkPromptpay.h>

const char* tax = "XXXXXXXXX";
float amount = 1.10;
const char* ssid = "XXXX";
const char* pass = "XXXXXXXX";

SnailwalkPromptpay snail(tax , amount , ssid , pass);

void setup() {
  Serial.begin(115200);
  snail.begin();
}

void loop() {
  Serial.println(snail.genThaiQR());
  delay(5000);
}
