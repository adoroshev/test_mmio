#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#include "history.h"
#include "chars.h"
#include "print.h"

void console_do_action_for_char(struct console *con, char ch) {
	static struct history_node *current_node = NULL;
	static char input_buffer[80] = {0};
	size_t index = 0;
	enum char_type type = 0;
	if (con == NULL) {
		return;
	}
	type = chars_get_char_type(ch);
	switch(type) {
	case CHAR_IDLE:
		break;
	case CHAR_PRINTABLE:
		if (con->current_position == CONSOLE_MAX_INPUT_SIZE - 1) {
			break;
		}
		for (index = CONSOLE_MAX_INPUT_SIZE - 1;
			index > con->current_position; index--) {
			con->input_buffer[index] =
				con->input_buffer[index - 1];
		}
		con->input_buffer[con->current_position] = ch;
		memmove(input_buffer, con->input_buffer, CONSOLE_MAX_INPUT_SIZE);
		/* memmove(input_buffer, con->input_buffer, strlen(con->input_buffer) + 1); */
		con->current_position++;
		con->current_length++;
		break;
	case CHAR_NEWLINE:
		con->input_buffer[CONSOLE_MAX_INPUT_SIZE - 1] = '\0';
		command_string_to_command(con->input_buffer,
			con->current_command);
		print_newline();
		if (con->current_command->command != NULL) {
			history_add(con->input_history, con->input_buffer);
			current_node = con->input_history->head_node;
			console_execute_command(con);
		}
		memset(con->input_buffer, '\0', CONSOLE_MAX_INPUT_SIZE);
		memmove(input_buffer, con->input_buffer, strlen(con->input_buffer) + 1);
		con->current_length = 0;
		con->current_position = 0;
		print_input_prompt();
		break;
	case CHAR_BACKSPACE:
		if (con->current_position == 0) {
			break;
		}
		for (index = con->current_position - 1;
			index < CONSOLE_MAX_INPUT_SIZE - 1; index++) {
			con->input_buffer[index] =
				con->input_buffer[index + 1];
		}
		con->input_buffer[CONSOLE_MAX_INPUT_SIZE - 1] = '\0';
		con->current_position--;
		con->current_length--;
		break;
	case CHAR_ARROW_UP:
		if (con->input_history->node_count == 0) {
			break;
		}
		if (current_node->prev_node == con->input_history->tail_node) {
			break;
		}
		current_node = current_node->prev_node;
		memmove(con->input_buffer, current_node->input,
			strlen(current_node->input) + 1);
		con->current_length = strlen(con->input_buffer);
		con->current_position = con->current_length;
		break;
	case CHAR_ARROW_DOWN:
		if (con->input_history->node_count == 0) {
			break;
		}
		if (current_node == con->input_history->head_node) {
			break;
		}
		if (current_node->next_node == con->input_history->head_node) {
			memmove(con->input_buffer, input_buffer,
				strlen(input_buffer) + 1);
			current_node = current_node->next_node;
		} else {
			current_node = current_node->next_node;
			memmove(con->input_buffer, current_node->input,
				strlen(current_node->input) + 1);
		}
		con->current_length = strlen(con->input_buffer);
		con->current_position = con->current_length;
		break;
	case CHAR_ARROW_RIGHT:
		if (con->current_position == con->current_length) {
			break;
		}
		print_move_cursor_right();
		con->current_position++;
		break;
	case CHAR_ARROW_LEFT:
		if (con->current_position == 0) {
			break;
		}
		print_move_cursor_left();
		con->current_position--;
		break;
	case CHAR_INTERRUPT:
		printf("\r\nInput interrupted\r\n");
		print_line_reset();
		print_input_prompt();
		memset(con->input_buffer, '\0', CONSOLE_MAX_INPUT_SIZE);
		memset(input_buffer, '\0', CONSOLE_MAX_INPUT_SIZE);
		con->current_position = 0;
		con->current_length = 0;
		break;
	case CHAR_QUIT:
		write(1, "\r\nCtrl+C\r\n", 10);
		exit(0);
		break;
	case CHAR_UNSUPPORTED:
		break;
	};
}

