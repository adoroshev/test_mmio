#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include "console.h"
#include "history.h"
#include "print.h"

void console_run(struct console *con) {
	int bytes_read = 0;
	char ch = 0;
	if (con == NULL) {
		return;
	}
	print_header();
	print_input_prompt();
	while (1) {
		bytes_read = read(0, &ch, 1);
		if (bytes_read == 0) {
			ch = 0;
		}
		console_do_action_for_char(con, ch);
		print_line_reset();
		print_input_prompt();
		printf("%s\033[%zuG", con->input_buffer, 3 + con->current_position);
		fflush(stdout);
	}
}

