#include <unistd.h>
#include "print.h"

void print_screen_clear(void) {
	write(1, "\033[2J\033[H", 7);
}

