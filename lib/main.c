#include <stdio.h>
#include "termui.c"

int main(void){
	// Test the library methods here
	termui_init();

	if (TERMUI_INITIALIZED_FLAG) puts("Termui has been initialized succesfully!");
	else puts("Termui hasn't been initialized!");

	printf("CURSOR_X_COORD at %p is: %ld\n", CURSOR_X_COORD_ADDR, CURSOR_X_COORD);
	printf("CURSOR_Y_COORD at %p is: %ld\n", CURSOR_Y_COORD_ADDR, CURSOR_Y_COORD);

	termui_box_create_at(3, 3, 0, CURSOR_Y_COORD + 3, '@');
	termui_box_create(3, 3, '@');

	termui_text_box("Hello, in a really really long long message at all\nur dummy dummy", 3, '@');
	_TERMUI_MOVE_TO(10, 10);

	return 0;
}
