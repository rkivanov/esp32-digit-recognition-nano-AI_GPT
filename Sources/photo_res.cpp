// === photo_res.cpp ===
#include "photo_res.h"
#include <Arduino.h>

#define LIGHT_SENSOR_PIN 34

int read_light_sensor() {
  return analogRead(LIGHT_SENSOR_PIN);
}