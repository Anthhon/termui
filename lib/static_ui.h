#ifndef STATIC_UI_H
#define STATIC_UI_H

// Draws a border using the specified character
#include <string.h>
void termui_draw_border(const char border_char){
	size_t x = (size_t)TERM_X_SIZE;
	size_t y = (size_t)TERM_Y_SIZE;

	// Draw border
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i, j);
			printf("%c", border_char);
		}
	}
	termui_get_pos(); // Updates cursor pos
}

// Creates a box with the specified dimensions and border character
void termui_box_create(const size_t x, const size_t y, const char border_char){
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i + CURSOR_X_COORD, j + CURSOR_Y_COORD);
			printf("%c", border_char);
		}
	}
	termui_get_pos(); // Updates cursor pos
}

// Creates a box with the specified dimensions, border character, and starting coordinates
void termui_box_create_at(const size_t x, const size_t y, const size_t x_coord, const size_t y_coord, const char border_char){
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			_TERMUI_MOVE_TO(i + x_coord, j + y_coord);
			printf("%c", border_char);
		}
	}
	termui_get_pos(); // Updates cursor pos
}

// Creates a text box with a message inside and a border
// TODO: Text box cannot deal with '\n' characters
void termui_text_box(char *message, const size_t offset, const char border_char){
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;

	// Build box
	termui_get_pos(); // Updates cursor pos
	size_t last_x = *CURSOR_X_COORD_ADDR;
	size_t last_y = *CURSOR_Y_COORD_ADDR;
	termui_box_create(x, y, border_char);

	// Count newlines at message to calculate offset
	char *msg_ptr = &message[0];
	size_t newline_offset = 0;
	while (*msg_ptr != '\0'){
		if (*msg_ptr == '\n'){
			++newline_offset;
		}
		++msg_ptr;
	}
	if (newline_offset != 0) --newline_offset;

	// Print message
	msg_ptr = &message[0]; // Reset pointer
	size_t line_length = 0;
	_TERMUI_MOVE_TO(last_x + offset + 2, last_y + offset + 2 - newline_offset);
	termui_get_pos();
	while(*msg_ptr != '\0'){
		if (*msg_ptr == '\n'){
			_TERMUI_MOVE_TO(CURSOR_X_COORD + 1, ++CURSOR_Y_COORD);
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
	/////////////////////////////////
	_TERMUI_MOVE_TO(CURSOR_X_COORD, CURSOR_Y_COORD);
}

// Creates a text box with a message inside, a border, and starting coordinates
// TODO: Text box cannot deal with '\n' characters
void termui_text_box_at(char *message, const size_t offset, const size_t x_coord, const size_t y_coord, const char border_char){
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;

	// Build box
	termui_get_pos(); // Updates cursor pos
	size_t last_x = CURSOR_X_COORD;
	size_t last_y = CURSOR_Y_COORD;
	termui_box_create_at(x, y, x_coord, y_coord, border_char);

	// Print message at given coordinate
	_TERMUI_MOVE_TO(x_coord + offset + 2, y_coord + offset + 2);
	printf("%s", message);
	_TERMUI_MOVE_TO(CURSOR_X_COORD, CURSOR_Y_COORD);
}

#endif /* STATIC_UI_H */
