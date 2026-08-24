#include <unistd.h>
#include "print.h"

void print_move_cursor_left(void) {
	write(1, "\033[1D", 4);
}

