#include <unistd.h>
#include "print.h"

void print_newline(void) {
	write(1, "\r\n", 2);
}

