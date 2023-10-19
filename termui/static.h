#ifndef STATIC_UI_H
#define STATIC_UI_H

void termui_draw_border(terminalStatus *terminal, const char border_char);
void termui_box_create(terminalStatus *terminal, const int x, const int y, const char border_char);
void termui_box_create_at(terminalStatus *terminal, const int x, const int y, const int x_coord, const int y_coord, const char border_char);
void termui_text_box(terminalStatus *terminal, char *message, const int offset, const char border_char);
void termui_text_box_at(terminalStatus *terminal, char *message, const int offset, const int x_coord, const int y_coord, const char border_char);

#endif /* STATIC_UI_H */
