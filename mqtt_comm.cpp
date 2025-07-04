#include <Arduino.h>
#include "mqtt_comm.h"
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("ai/decision");
    } else {
      Serial.print(".");
      delay(5000);
    }
  }
  Serial.println("MQTT client is connected!");
}

void mqtt_setup(const char* mqtt_server) {
  client.setServer(mqtt_server, 1883);
}
/*Sets the message handler — a function pointer
That function gets called when any subscribed topic receives a message*/
void mqtt_set_callback(void (*callback)(char*, byte*, unsigned int)) {
  client.setCallback(callback);
}

void mqtt_loop() {
  if (!client.connected()) reconnect();
  client.loop();
}

void mqtt_publish(const char* topic, const char* message) {
  client.publish(topic, message);
}