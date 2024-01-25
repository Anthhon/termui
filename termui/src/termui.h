#ifndef TERMUI_H
#define TERMUI_H

#define MoveTo(x, y) (void)printf("\e[%d;%dH", y, x)
#define ClearLine(y) (void)printf("\e[%d;1H", y); \
		     (void)printf("\e[K\r");
//#define GoLeft() MoveTo(--CURSOR_X_COORD, CURSOR_Y_COORD)
//#define GoRight() MoveTo(++CURSOR_X_COORD, CURSOR_Y_COORD)
//#define GoUp() MoveTo(CURSOR_X_COORD, --CURSOR_Y_COORD)
//#define GoDown() MoveTo(CURSOR_X_COORD, ++CURSOR_Y_COORD)

typedef struct terminalInfo {
	bool initialized;
	int x_term_size;
	int y_term_size;
	int x_cursor_coord;
	int y_cursor_coord;
}terminalInfo;

typedef struct {
	int max_size;
	int x_position;
	int y_position;
} fieldContext;

void termuiInit(terminalInfo *terminal);
void getPosition(terminalInfo *terminal);
void getTermSize(terminalInfo *terminal);
void clearScreen(void);

#include "static.h"

#endif /* TERMUI_H */
