#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>
extern TFT_eSPI tft;

void display_init();
void print_touch_to_display(int x, int y, int z);
void print_touch_to_serial(int x, int y, int z);
void print_light_brightness(int x);

#endif
