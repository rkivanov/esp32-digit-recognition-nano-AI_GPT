#include "touch.h"
#include "ui.h"
//#include "drawbuffer.h"
#include "mqtt_comm.h"
#include "wifi_comm.h"
#include "display.h"

// WiFi definitions
const char* ssid = "Auto_Platforms";
const char* password = "qazwsxed";
//MQTT definitions
const char* mqtt_ip = "192.168.1.20"; // Jetson nano MQTT broker Do you need anything from me?

void app_setup() {
  Serial.begin(115200);
  wifi_connect(ssid,password);           // WiFi setup
  mqtt_setup(mqtt_ip); // MQTT server IP (example)
  mqtt_set_callback([](char* topic, byte* payload, unsigned int length) {
    Serial.print("[MQTT] Message arrived on topic: ");
    Serial.println(topic);
    // Process message here if needed
  });
  display_init();           // Set up display  
  touch_init();             // Attach interrupt or polling touch init
  ui_init();                // Draw initial UI layout
}

void app_loop() {
  mqtt_loop();  // keep MQTT connection alive

  int x, y, z;
  if (read_touch(x, y, z)) {
    Serial.printf("Touch at (%d, %d) pressure: %d\n", x, y, z);

    if (is_in_draw_area(x, y)) {
      //apply_pressure_brush(x, y, z);  // draw and buffer (to be implemented)
    }
    else if (is_in_button_clear(x, y)) {
      //clear_draw_buffer();
      ui_init();
    }
    else if (is_in_button_send(x, y)) {
      // Will later convert buffer and publish to Nano
      Serial.println("[Send] Triggered (not yet implemented)");
    }
  }
}
