#include <stdlib.h>
#include "command.h"

void command_free(struct command *cmd) {
	size_t index = 0;
	if (cmd == NULL) {
		return;
	}
	free(cmd->command);
	cmd->command = NULL;
	for (index = 0; index < cmd->argument_count; index++) {
		free(cmd->arguments[index]);
		cmd->arguments[index] = NULL;
	}
	free(cmd->arguments);
	cmd->arguments = NULL;
	cmd->argument_count = 0;
}

