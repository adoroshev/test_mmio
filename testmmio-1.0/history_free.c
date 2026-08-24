#include <stdlib.h>
#include "history.h"

void history_free(struct history *hist) {
	struct history_node *curr_node = NULL;
	struct history_node *next_node = NULL;
	if (hist == NULL) {
		return;
	}
	curr_node = hist->tail_node;
	if (curr_node == NULL) {
		return;
	}
	while (curr_node != NULL) {
		next_node = curr_node->next_node;
		history_node_free(curr_node);
		free(curr_node);
		curr_node = next_node;
	}
	hist->tail_node = NULL;
	hist->head_node = NULL;
	hist->node_count = 0;
}

