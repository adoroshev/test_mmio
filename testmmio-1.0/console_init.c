#include <stdlib.h>
#include <string.h>
#include "console.h"
#include "history.h"

void console_init(struct console *con) {
	if (con == NULL) {
		return;
	}
	memset(con->input_buffer, '\0', CONSOLE_MAX_INPUT_SIZE);
	con->current_position = 0;
	con->current_length = 0;
	con->input_history = (struct history *)malloc(sizeof(struct history));
	history_init(con->input_history);
	con->current_command = (struct command *)
		malloc(sizeof(struct command));
	command_init(con->current_command);
}

