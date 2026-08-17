#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "console.h"
#include "command.h"
#include "print.h"
#include "mmio.h"

void console_execute_command(struct console *con) {
	size_t mem = 0;
	size_t value = 0;
	if (con == NULL || con->current_command == NULL) {
		return;
	}
	if (0 == strcmp(con->current_command->command, "quit")) {
		if (con->current_command->argument_count != 0) {
			printf("Command 'quit' does not need arguments\r\n");
			return;
		}
		exit(0);
	}
	if (0 == strcmp(con->current_command->command, "help")) {
		if (con->current_command->argument_count != 0) {
			printf("Command 'help' does not need arguments\r\n");
			return;
		}
		print_help();
		return;
	}
	if (0 == strcmp(con->current_command->command, "clear")) {
		if (con->current_command->argument_count != 0) {
			printf("Command 'clear' does not need arguments\r\n");
			return;
		}
		print_screen_clear();
		return;
	}
	if (0 == strcmp(con->current_command->command, "history")) {
		if (con->current_command->argument_count != 0) {
			printf(
				"Command 'history' does not need arguments\r\n"
			);
			return;
		}
		history_print(con->input_history);
		return;
	}	
	if (0 == strcmp(con->current_command->command, "iorb")) {
		if (con->current_command->argument_count != 1) {
			printf("Command 'iorb' takes 1 argument\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		printf("0x%zX\r\n", mmio_iorb((void *)mem));
		return;
	}
	if (0 == strcmp(con->current_command->command, "iorw")) {
		if (con->current_command->argument_count != 1) {
			printf("Command 'iorw' takes 1 argument\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		printf("0x%zX\r\n", mmio_iorw((void *)mem));
		return;
	}
	if (0 == strcmp(con->current_command->command, "iord")) {
		if (con->current_command->argument_count != 1) {
			printf("Command 'iord' takes 1 argument\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		printf("0x%zX\r\n", mmio_iord((void *)mem));
		return;
	}
	if (0 == strcmp(con->current_command->command, "iowb")) {
		if (con->current_command->argument_count != 2) {
			printf("Command 'iowb' takes 2 arguments\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		mmio_iowb((void *)mem, value);
		return;
	}
	if (0 == strcmp(con->current_command->command, "ioww")) {
		if (con->current_command->argument_count != 2) {
			printf("Command 'ioww' takes 2 arguments\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		mmio_ioww((void *)mem, value);
		return;
	}
	if (0 == strcmp(con->current_command->command, "iowd")) {
		if (con->current_command->argument_count != 2) {
			printf("Command 'iowd' takes 2 arguments\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		mmio_iowd((void *)mem, value);
		return;
	}
	if (0 == strcmp(con->current_command->command, "mmrb")) {
		if (con->current_command->argument_count != 1) {
			printf("Command 'mmrb' takes 1 argument\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		printf("0x%X\r\n", mmio_mmrb((void *)mem));
		return;
	}
	if (0 == strcmp(con->current_command->command, "mmwb")) {
		if (con->current_command->argument_count != 2) {
			printf("Command 'mmwb' takes 2 arguments\r\n");
			return;
		}
		mem = mmio_get_memory_address(
			con->current_command->arguments[0]);
		if (mem == -1) {
			printf("Invalid memory address '%s'\r\n",
				con->current_command->arguments[0]);
		}
		value = mmio_get_memory_address(
			con->current_command->arguments[1]);
		if (value == -1) {
			printf("Incorrect value '%s'\r\n",
				con->current_command->arguments[1]);
		}
		mmio_mmwb((void *)mem, (uint8_t)value);
		return;
	}
	printf("Invalid command '%s'\r\n", con->current_command->command);

}

