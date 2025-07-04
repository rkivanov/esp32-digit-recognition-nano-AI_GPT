#include <Arduino.h>
//#include <TFT_eSPI.h>
#include "display.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2

TFT_eSPI tft = TFT_eSPI();

void display_init() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  tft.drawCentreString("Hello, world!", SCREEN_WIDTH / 2, 30, FONT_SIZE);
  tft.drawCentreString("Touch screen to test", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, FONT_SIZE);
  Serial.println("Display init completed");
}

void print_touch_to_serial(int x, int y, int z) {
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(" | Y = ");
  Serial.print(y);
  Serial.print(" | Pressure = ");
  Serial.println(z);
}

void print_touch_to_display(int x, int y, int z) {
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  int centerX = SCREEN_WIDTH / 2;
  int textY = 80;

  tft.drawCentreString("X = " + String(x), centerX, textY, FONT_SIZE);
  tft.drawCentreString("Y = " + String(y), centerX, textY + 20, FONT_SIZE);
  tft.drawCentreString("Pressure = " + String(z), centerX, textY + 40, FONT_SIZE);
}

void print_light_brightness(int x) {
//  tft.fillScreen(TFT_WHITE);
//  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  int centerX = SCREEN_WIDTH / 2;
  int textY = 10;

  tft.drawCentreString("Light_brightness = " + String(x), centerX, textY, FONT_SIZE);
}
