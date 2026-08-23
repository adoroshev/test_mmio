#include <stdlib.h>
#include "history.h"

void history_init(struct history *hist) {
	if (hist == NULL) {
		return;
	}
	hist->head_node = (struct history_node *)
		malloc(sizeof(struct history_node));
	hist->tail_node = (struct history_node *)
		malloc(sizeof(struct history_node));
	history_node_init(hist->tail_node);
	history_node_init(hist->head_node);
	hist->tail_node->next_node = hist->head_node;
	hist->head_node->prev_node = hist->tail_node;
	hist->node_count = 0;
}

