// === wifi_comm.cpp ===
#include <Arduino.h>
#include <WiFi.h>
#include "wifi_comm.h"


void wifi_connect(const char* ssid, const char* password) {
  delay(10);
  WiFi.begin(ssid, password);
  int retries = 20;
while (WiFi.status() != WL_CONNECTED && retries-- > 0) {
  delay(500);
  Serial.print(".");
}
if (WiFi.status() == WL_CONNECTED) {
  Serial.println("WiFi connected!");
} else {
  Serial.println("WiFi failed!");
}
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}