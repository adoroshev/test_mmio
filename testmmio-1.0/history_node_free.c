#include <stdlib.h>
#include "history.h"

/* This function should not be called by the user, only by history_free */
/* history_free is responsible for freeing prev_node and next_node      */

void history_node_free(struct history_node *node) {
	if (node == NULL) {
		return;
	}
	node->prev_node = NULL;
	node->next_node = NULL;
	free(node->input);
	node->input = NULL;
}

