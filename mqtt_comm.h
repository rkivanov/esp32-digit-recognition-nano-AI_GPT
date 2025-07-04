#ifndef MQTT_COMM_H
#define MQTT_COMM_H

#include <Arduino.h>

void mqtt_setup(const char* mqtt_server);
void mqtt_loop();
void mqtt_publish(const char* topic, const char* message);
void mqtt_set_callback(void (*callback)(char*, byte*, unsigned int));

#endif