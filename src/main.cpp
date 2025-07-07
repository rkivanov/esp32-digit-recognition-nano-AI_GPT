#include <Arduino.h>
//#include "wifi_comm.h"
//#include "mqtt_comm.h"
//#include "display.h"
//#include "touch.h"
//#include "ui.h"
#include "main_logic.h"

// WiFi definitions
//const char* ssid = "Auto_Platforms";
//const char* password = "qazwsxed";

//MQTT definitions
//const char* mqtt_ip = "192.168.1.20"; // Jetson nano MQTT broker
// Example callback function for received MQTT messages
void handle_incoming_mqtt(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]: ");

  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
//WiFiClient espClient;
//PubSubClient client(espClient);

void setup() {
//  Serial.begin(115200);
// WiFi setup
//  setup_wifi(ssid, password);
// MQTT setup  
//  mqtt_setup(mqtt_ip);
//  mqtt_set_callback(handle_incoming_mqtt); //Assign MQTT message callback
// Display setup
//  display_init();
// Touch setup
//  touch_init();
// UI setup  
//  ui_init();
  app_setup();
}

void loop() {
 
}