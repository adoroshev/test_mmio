#include <stdlib.h>
#include "history.h"

void history_node_init(struct history_node *node) {
	if (node == NULL) {
		return;
	}
	node->prev_node = NULL;
	node->next_node = NULL;
	node->input = NULL;
}

