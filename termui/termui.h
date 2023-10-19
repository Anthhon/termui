#ifndef TERMUI_H
#define TERMUI_H

#define _TERMUI_MOVE_TO(x, y) (void)printf("\e[%d;%dH", y, x)
#define _TERMUI_GO_LEFT() _TERMUI_MOVE_TO(--CURSOR_X_COORD, CURSOR_Y_COORD)
#define _TERMUI_GO_RIGHT() _TERMUI_MOVE_TO(++CURSOR_X_COORD, CURSOR_Y_COORD)
#define _TERMUI_GO_UP() _TERMUI_MOVE_TO(CURSOR_X_COORD, --CURSOR_Y_COORD)
#define _TERMUI_GO_DOWN() _TERMUI_MOVE_TO(CURSOR_X_COORD, ++CURSOR_Y_COORD)

typedef struct terminalStatus {
	int termui_initialized;
	int x_term_size; // Horizontal window size
	int y_term_size; // Vertical window size
	int x_cursor_coord; // X cursor coordinates
	int y_cursor_coord; // Y cursor coordinates
}terminalStatus;

void termui_init(terminalStatus *terminal);
void termui_get_pos(terminalStatus *terminal);
void termui_get_term_size(terminalStatus *terminal);

#include "static.h"

#endif /* TERMUI_H */
