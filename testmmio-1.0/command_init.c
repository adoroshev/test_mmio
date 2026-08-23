#include <stdlib.h>
#include "command.h"

void command_init(struct command *cmd) {
	if (cmd == NULL) {
		return;
	}
	cmd->command = NULL;
	cmd->arguments = NULL;
	cmd->argument_count = 0;
}

