#include <stdio.h>

#include "termui.h"

terminalStatus term_info = {0};

int main(void){
	// Test the library methods here
	termui_init(&term_info);

	termui_text_box(&term_info, "Hello, in a really really long long message at all\nur dummy dummy\nanother new line", 3, '@');
	_TERMUI_MOVE_TO(0, 10);

	return 0;
}
