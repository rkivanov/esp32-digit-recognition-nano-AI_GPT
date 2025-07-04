#include "ui.h"
//#include <TFT_eSPI.h>
#include "display.h"

// UI zone positions
#define DRAW_X      20
#define DRAW_Y      30
#define DRAW_W      112
#define DRAW_H      112

#define BTN_SEND_X  140
#define BTN_SEND_Y  30
#define BTN_SEND_W  60
#define BTN_SEND_H  30

#define BTN_CLR_X   210
#define BTN_CLR_Y   30
#define BTN_CLR_W   100
#define BTN_CLR_H   30

#define RESULT_X    20
#define RESULT_Y    150
#define RESULT_W    60
#define RESULT_H    30

void ui_init() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  draw_ui_layout();
}

void draw_ui_layout() {
  tft.drawRect(DRAW_X, DRAW_Y, DRAW_W, DRAW_H, TFT_RED);
  tft.drawRect(BTN_SEND_X, BTN_SEND_Y, BTN_SEND_W, BTN_SEND_H, TFT_BLACK);
  tft.drawRect(BTN_CLR_X, BTN_CLR_Y, BTN_CLR_W, BTN_CLR_H, TFT_BLACK);
  tft.drawRect(RESULT_X, RESULT_Y, RESULT_W, RESULT_H, TFT_BLACK);

  draw_button_labels();
}

void draw_button_labels() {
  tft.drawCentreString("Send", BTN_SEND_X + BTN_SEND_W / 2, BTN_SEND_Y + 8, 2);
  tft.drawCentreString("Clear", BTN_CLR_X + BTN_CLR_W / 2, BTN_CLR_Y + 8, 2);
  tft.drawCentreString("?", RESULT_X + RESULT_W / 2, RESULT_Y + 8, 2);
}

void draw_result(int digit) {
  tft.fillRect(RESULT_X, RESULT_Y, RESULT_W, RESULT_H, TFT_WHITE);
  tft.drawRect(RESULT_X, RESULT_Y, RESULT_W, RESULT_H, TFT_BLACK);
  tft.drawCentreString(String(digit), RESULT_X + RESULT_W / 2, RESULT_Y + 8, 2);
}

bool is_in_draw_area(int x, int y) {
  return x >= DRAW_X && x <= DRAW_X + DRAW_W &&
         y >= DRAW_Y && y <= DRAW_Y + DRAW_H;
}

bool is_in_button_send(int x, int y) {
  return x >= BTN_SEND_X && x <= BTN_SEND_X + BTN_SEND_W &&
         y >= BTN_SEND_Y && y <= BTN_SEND_Y + BTN_SEND_H;
}

bool is_in_button_clear(int x, int y) {
  return x >= BTN_CLR_X && x <= BTN_CLR_X + BTN_CLR_W &&
         y >= BTN_CLR_Y && y <= BTN_CLR_Y + BTN_CLR_H;
}
