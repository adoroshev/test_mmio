#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "command.h"

void command_string_to_command(const char *str, struct command *cmd) {
	char *temp_str = NULL;
	char *token = NULL;
	size_t count = 0;
	size_t len = 0;
	command_free(cmd);
	if (cmd == NULL || str == NULL || *str == '\0') {
		return;
	}
	len = strlen(str);
	temp_str = (char *)malloc(len + 1);
	memmove(temp_str, str, len + 1);
	token = strtok(temp_str, " ");
	if (token == NULL) {
		goto cleanup;
	}	
	len = strlen(token);
	cmd->command = (char *)malloc(len + 1);
	memmove(cmd->command, token, len + 1);
	while ((token = strtok(NULL, " ")) != NULL) {
		len = strlen(token);
		cmd->arguments = (char **)
			realloc(cmd->arguments, sizeof(char *) * (count + 1));
		cmd->arguments[count] = (char *)malloc(len + 1);
		memmove(cmd->arguments[count], token, len + 1);
		count++;
	}
	cmd->argument_count = count;
cleanup:
	free(temp_str);
}

