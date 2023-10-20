#include <stdio.h>

#include "termui.h"

terminalInfo term_info = {0};

int main(void)
{
	// Test the library methods here
	termuiInit(&term_info);

	boxText(&term_info, "Hello, in a really really long long message at all\nur dummy dummy\nanother new line", 3, '@');
	MoveTo(0, 10);

	return 0;
}
