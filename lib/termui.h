#ifndef TERMUI_H
#define TERMUI_H

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define CURSOR_X_COORD_ADDR &term_info.x_cursor_coord
#define CURSOR_Y_COORD_ADDR &term_info.y_cursor_coord

typedef struct {
	size_t x_win_size; // Horizontal window size
	size_t y_win_size; // Vertical window size
	size_t x_cursor_coord; // X cursor coordinates
	size_t y_cursor_coord; // Y cursor coordinates
} TerminalStatus;
TerminalStatus term_info;

void termui_move_to(const size_t x, const size_t y);

// Stores the cursor position
void termui_get_pos(void){
	int x, y;
	int t = STDOUT_FILENO;
	struct termios old_terminal_settings;

	// Get the current terminal settings
	tcgetattr(t, &old_terminal_settings);

	// Disable echoing and canonical mode
	struct termios new_terminal_settings = old_terminal_settings;
	new_terminal_settings.c_lflag &= ~(ECHO | ICANON);

	// Apply the modified terminal settings
	tcsetattr(t, TCSANOW, &new_terminal_settings);

	// Request cursor position
	printf("\033[6n"); 
	fflush(stdout);

	// Store cursor position
	scanf("\033[%d;%dR", CURSOR_Y_COORD_ADDR, CURSOR_X_COORD_ADDR);

	// Restore the original terminal settings
	tcsetattr(t, TCSANOW, &old_terminal_settings);
}

// Retrieves the window size of the terminal
void termui_get_windows_size(void){
	struct winsize size;

	ioctl(0, TIOCGWINSZ, &size); // Uses ioctl system call to update terminal size values
	term_info.x_win_size = size.ws_col;
	term_info.y_win_size = size.ws_row;
}

void termui_go_left(void){
	// Stores actual position
	termui_get_pos();
	termui_move_to(term_info.x_cursor_coord - 1, term_info.y_cursor_coord);
}

void termui_go_right(void){
	// Stores actual position
	termui_get_pos();
	termui_move_to(term_info.x_cursor_coord + 1, term_info.y_cursor_coord);
}

void termui_go_up(void){
	// Stores actual position
	termui_get_pos();
	termui_move_to(term_info.x_cursor_coord, term_info.y_cursor_coord - 1);
}

void termui_go_down(void){
	// Stores actual position
	termui_get_pos();
	termui_move_to(term_info.x_cursor_coord, term_info.y_cursor_coord + 1);
}

// Moves the cursor to the specified coordinates
void termui_move_to(const size_t x, const size_t y){
	(void)printf("\e[%lu;%luH", y, x); // Uses escape characters to move cursor
}

#include "static_ui.h"

#endif /* TERMUI_H */
