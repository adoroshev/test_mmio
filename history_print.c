#include <stdio.h>
#include <stdlib.h>
#include "history.h"

static int get_max_number_length(size_t number);

void history_print(const struct history *hist) {
	struct history_node *node = NULL;
	size_t index = 1;
	int depth = 0;
	if (hist == NULL) {
		return;
	}
	if (hist->node_count == 0) {
		return;
	}
	depth = get_max_number_length(hist->node_count);
	node = hist->tail_node->next_node;
	while (node != hist->head_node) {
		printf("%*zu  %s\r\n", depth, index, node->input);
		index++;
		node = node->next_node;
	}
}

static int get_max_number_length(size_t number) {
	int len = 0;
	if (number == 0) {
		return 1;
	}
	while (number) {
		len++;
		number /= 10;
	}
	return len;
}

