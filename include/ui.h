#ifndef UI_HANDLER_H
#define UI_HANDLER_H

void ui_init();
void draw_ui_layout();
void draw_result(int digit);
void draw_button_labels();

bool is_in_draw_area(int x, int y);
bool is_in_button_send(int x, int y);
bool is_in_button_clear(int x, int y);

#endif
