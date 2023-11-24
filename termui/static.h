#ifndef STATIC_UI_H
#define STATIC_UI_H

#include "termui.h"

void boxBuild(terminalInfo *terminal, const int x, const int y, const char border_char);
void boxBuildAt(terminalInfo *terminal, const int x, const int y, const int x_coord, const int y_coord, const char border_char);
void boxText(terminalInfo *terminal, char *message, const int offset, const char border_char);
void boxTextAt(terminalInfo *terminal, char *message, const int offset, const int x_coord, const int y_coord, const char border_char);
void fieldText(fieldContext *field, const char *text);
void footerText(terminalInfo *terminal, const char *text, int offset);
void drawBorder(terminalInfo *terminal, const char border_char);

#endif /* STATIC_UI_H */
