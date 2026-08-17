#include <stdlib.h>
#include <string.h>
#include "history.h"

void history_node_set_input(struct history_node *node, const char *input) {
	size_t len = 0;
	if (node == NULL || input == NULL) {
		return;
	}
	len = strlen(input);
	if (node->input != NULL) {
		free(node->input);
	}
	node->input = (char *)malloc(len + 1);
	memmove(node->input, input, len);
	node->input[len] = '\0';
}

