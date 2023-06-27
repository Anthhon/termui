#ifndef TERMUI_H
#define TERMUI_H

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef struct {
	size_t x_win_size; // Horizontal window size
	size_t y_win_size; // Vertical window size
} TerminalStatus;
TerminalStatus term_info;

// Retrieves the cursor position from the terminal
// TODO: Remove escape char echo in terminal when executing
void termui_get_cursor_pos()
{
	int x, y;

	printf("\033[6n");
	fflush(stdout);
	scanf("\033[%d;%dR", &y, &x);
	printf("Cursor Position: x = %d, y = %d\n", x, y);
}

// Retrieves the window size of the terminal
void termui_get_windows_size(){
	struct winsize size;

	ioctl(0, TIOCGWINSZ, &size); // Uses ioctl system call to update terminal size values
	term_info.x_win_size = size.ws_col;
	term_info.y_win_size = size.ws_row;
}


// Moves the cursor to the specified coordinates
void termui_move_to(const size_t x, const size_t y){
	(void)printf("\e[%lu;%luH", y, x); // Uses escape characters to move cursor
}

#include "static_ui.h"

#endif /* TERMUI_H */
