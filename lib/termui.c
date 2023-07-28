#ifndef TERMUI_H
#define TERMUI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define TERMUI_INITIALIZED_FLAG term_info.termui_initialized
#define TERM_X_SIZE term_info.x_term_size
#define TERM_Y_SIZE term_info.y_term_size
#define CURSOR_X_COORD term_info.x_cursor_coord
#define CURSOR_Y_COORD term_info.y_cursor_coord
#define CURSOR_X_COORD_ADDR &term_info.x_cursor_coord
#define CURSOR_Y_COORD_ADDR &term_info.y_cursor_coord

#define _TERMUI_MOVE_TO(x, y) (void)printf("\e[%lu;%luH", y, x)
#define _TERMUI_GO_LEFT() _TERMUI_MOVE_TO(--CURSOR_X_COORD, CURSOR_Y_COORD)
#define _TERMUI_GO_RIGHT() _TERMUI_MOVE_TO(++CURSOR_X_COORD, CURSOR_Y_COORD)
#define _TERMUI_GO_UP() _TERMUI_MOVE_TO(CURSOR_X_COORD, --CURSOR_Y_COORD)
#define _TERMUI_GO_DOWN() _TERMUI_MOVE_TO(CURSOR_X_COORD, ++CURSOR_Y_COORD)

void termui_get_pos(void);
void termui_get_term_size(void);
void termui_draw_border(const char border_char);
void termui_box_create(const size_t x, const size_t y, const char border_char);
void termui_box_create_at(const size_t x, const size_t y, const size_t x_coord, const size_t y_coord, const char border_char);
void termui_text_box(char *message, const size_t offset, const char border_char);
void termui_text_box_at(char *message, const size_t offset, const size_t x_coord, const size_t y_coord, const char border_char);

typedef struct {
	bool termui_initialized;
	size_t x_term_size; // Horizontal window size
	size_t y_term_size; // Vertical window size
	size_t x_cursor_coord; // X cursor coordinates
	size_t y_cursor_coord; // Y cursor coordinates
} TerminalStatus;
TerminalStatus term_info = { }; // 0'ed struct initialization

void termui_init(void){
	termui_get_pos();
	termui_get_term_size();
	TERMUI_INITIALIZED_FLAG = true;
}

// Stores the cursor position
void termui_get_pos(void){
	int x, y;
	int t = STDOUT_FILENO;
	struct termios old_terminal_settings;

	// Get the current terminal settings
	if (tcgetattr(t, &old_terminal_settings) == -1){
		(void)fprintf(stderr, "ERROR: failed to get terminal settings");
		exit(EXIT_FAILURE);
	}

	// Disable echoing and canonical mode
	struct termios new_terminal_settings = old_terminal_settings;
	new_terminal_settings.c_lflag &= ~(ECHO | ICANON);

	// Apply the modified terminal settings
	if (tcsetattr(t, TCSANOW, &new_terminal_settings) == -1){
		(void)fprintf(stderr, "ERROR: failed to change terminal settings");
		exit(EXIT_FAILURE);
	}

	// Request cursor position
	printf("\033[6n"); 
	fflush(stdout);

	// Store cursor position
	(void)scanf("\033[%ld;%ldR", CURSOR_Y_COORD_ADDR, CURSOR_X_COORD_ADDR);
	*CURSOR_X_COORD_ADDR -= 1; // Corrects offset
	*CURSOR_Y_COORD_ADDR -= 1; // Corrects offset

	// Restore the original terminal settings
	if (tcsetattr(t, TCSANOW, &old_terminal_settings) == -1){
		(void)fprintf(stderr, "ERROR: failed to restore terminal settings");
		exit(EXIT_FAILURE);
	}
}

// Retrieves the window size of the terminal
void termui_get_term_size(void){
	struct winsize size;

	if (ioctl(0, TIOCGWINSZ, &size) == -1){
		(void)fprintf(stderr, "ERROR: ioctl call failed while getting terminal size");
		exit(EXIT_FAILURE);
	}; 

	// Uses ioctl system call to update terminal size values
	TERM_X_SIZE = size.ws_col;
	TERM_Y_SIZE = size.ws_row;
}

#include "static_ui.h"

#endif /* TERMUI_H */
