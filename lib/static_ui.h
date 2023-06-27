#ifndef STATIC_UI_H
#define STATIC_UI_H

// Draws a border using the specified character
void termui_draw_border(char border_char){
	termui_get_windows_size(); // Updates window size
	size_t x = (size_t)term_info.x_win_size;
	size_t y = (size_t)term_info.y_win_size;

	// Draw border
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			termui_move_to(i, j);
			printf("%c", border_char);
		}
	}
}

// Creates a box with the specified dimensions and border character
void termui_box_create(const size_t x, const size_t y, char border_char){
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			termui_move_to(i, j);
			printf("%c", border_char);
		}
	}
}

// Creates a box with the specified dimensions, border character, and starting coordinates
void termui_box_create_at(const size_t x, const size_t y, const size_t x_coord, const size_t y_coord, char border_char){
	// Build box
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			termui_move_to(i + x_coord, j + y_coord);
			printf("%c", border_char);
		}
	}
}

// Creates a text box with a message inside and a border
void termui_text_box(char *message, char border_char, const size_t offset){
	// Build box
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			termui_move_to(i, j);
			printf("%c", border_char);
		}
	}
	// Print message
	termui_move_to(offset * 2, offset * 2);
	printf("%s", message);
}

// Creates a text box with a message inside, a border, and starting coordinates
void termui_text_box_at(char *message, char border_char, const size_t offset, const size_t x_coord, const size_t y_coord){
	// Build box
	const size_t x = strlen(message) + offset * 2 + 2;
	const size_t y = offset * 2 + 3;
	for (size_t i = 1; i <= x; ++i){
		for (size_t j = 1; j <= y; ++j){
			if (j != 1 && j != y && i != 1 && i != x){
				continue;
			}
			termui_move_to(i + x_coord, j + y_coord);
			printf("%c", border_char);
		}
	}
	// Print message at given coordinate
	termui_move_to(offset * 2 + x_coord, offset * 2 + y_coord);
	printf("%s", message);
}

#endif /* STATIC_UI_H */
