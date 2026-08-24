#include <unistd.h>
#include "print.h"

void print_input_prompt(void) {
	write(1, "> ", 2);
}

