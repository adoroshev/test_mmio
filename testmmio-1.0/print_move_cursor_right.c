#include <unistd.h>
#include "print.h"

void print_move_cursor_right(void) {
	write(1, "\033[1C", 4);
}

