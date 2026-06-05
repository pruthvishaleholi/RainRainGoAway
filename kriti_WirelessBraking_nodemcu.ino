#define BLYNK_TEMPLATE_ID "TMPL39m2uJ2k4"
#define BLYNK_TEMPLATE_NAME "KritiBrahma"
#define BLYNK_AUTH_TOKEN "0_p_uMzqvdvomCLYPPKNcQhq51D_G3oo"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid[] = "GDA";
char pass[] = "polarbear456";

BLYNK_WRITE(V1) {
 int pinValue = param.asInt();  
  Serial.print(pinValue);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  delay(1000);
  Blynk.run();
}