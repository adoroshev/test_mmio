#include <unistd.h>
#include "print.h"

void print_line_reset(void) {
	write(1, "\033[2K\r", 5);
}

