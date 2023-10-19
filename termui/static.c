#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "termui.h"
#include "static.h"

// Draws a border using the specified character
void termui_draw_border(terminalStatus *terminal, const char border_char){
	int x = terminal->x_term_size;
	int y = terminal->y_term_size;

	// Draw border
	for (int i = 1; i <= x; ++i){
		for (int j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i, j);
			printf("%c", border_char);
		}
	}
	termui_get_pos(terminal); // Updates cursor pos
}

// Creates a box with the specified dimensions and border character
void termui_box_create(terminalStatus *terminal, const int x, const int y, const char border_char){
	for (int i = 1; i <= x; ++i){
		for (int j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i + terminal->x_cursor_coord, j + terminal->y_cursor_coord);
			printf("%c", border_char);
		}
	}
	termui_get_pos(terminal); // Updates cursor pos
}

// Creates a box with the specified dimensions, border character, and starting coordinates
void termui_box_create_at(terminalStatus *terminal, const int x, const int y, const int x_coord, const int y_coord, const char border_char){
	for (int i = 1; i <= x; ++i){
		for (int j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i + x_coord, j + y_coord);
			printf("%c", border_char);
		}
	}
	termui_get_pos(terminal); // Updates cursor pos
}

// Creates a text box with a message inside and a border
// TODO: Text box cannot deal with '\n' characters
void termui_text_box(terminalStatus *terminal, char *message, const int offset, const char border_char){
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;

	// Build box
	termui_get_pos(terminal); // Updates cursor pos
	int last_x = terminal->x_cursor_coord;
	int last_y = terminal->x_cursor_coord;
	termui_box_create(terminal, x, y, border_char);

	// Count newlines at message to calculate offset
	char *msg_ptr = &message[0];
	int newline_offset = 0;
	while (*msg_ptr != '\0'){
		if (*msg_ptr == '\n'){
			++newline_offset;
		}
		++msg_ptr;
	}
	if (newline_offset != 0) --newline_offset;

	// Print message
	msg_ptr = &message[0]; // Reset pointer
	int line_length = 0;

	_TERMUI_MOVE_TO(last_x + offset + 2, last_y + offset + 2 - newline_offset);
	termui_get_pos(terminal);
	while(*msg_ptr != '\0'){
		if (*msg_ptr == '\n'){
			_TERMUI_MOVE_TO(terminal->x_cursor_coord + 1, ++terminal->y_cursor_coord);
			fprintf(stdout, "\v"); // Break line
			line_length = 0;
			++msg_ptr;
			continue;
		}
		fprintf(stdout, "%c", *msg_ptr);
		++line_length;
		++msg_ptr;
	}
	fprintf(stdout, "\n");
	_TERMUI_MOVE_TO(terminal->x_cursor_coord, terminal->y_cursor_coord);
}

// Creates a text box with a message inside, a border, and starting coordinates
void termui_text_box_at(terminalStatus *terminal, char *message, const int offset, const int x_coord, const int y_coord, const char border_char){
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;

	// Build box
	termui_get_pos(terminal); // Updates cursor pos
	int last_x = terminal->x_cursor_coord;
	int last_y = terminal->y_cursor_coord;
	termui_box_create_at(terminal, x, y, x_coord, y_coord, border_char);

	// Print message at given coordinate
	_TERMUI_MOVE_TO(x_coord + offset + 2, y_coord + offset + 2);
	printf("%s", message);
	_TERMUI_MOVE_TO(terminal->x_cursor_coord, terminal->y_cursor_coord);
}

