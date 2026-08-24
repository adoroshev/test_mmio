#include <stdlib.h>
#include <string.h>
#include "console.h"
#include "history.h"

void console_free(struct console *con) {
	if (con == NULL) {
		return;
	}
	memset(con->input_buffer, '\0', CONSOLE_MAX_INPUT_SIZE);
	con->current_position = 0;
	con->current_length = 0;
	history_free(con->input_history);
	free(con->input_history);
	con->input_history = NULL;
	command_free(con->current_command);
	free(con->current_command);
	con->current_command = NULL;
}

