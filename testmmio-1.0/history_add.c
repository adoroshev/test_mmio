#include <stdlib.h>
#include "history.h"

void history_add(struct history *hist, const char *input) {
	struct history_node *new_node = NULL;
	struct history_node *temp = NULL;
	if (hist == NULL || input == NULL) {
		return;
	}
	new_node = (struct history_node *)malloc(sizeof(struct history_node));
	history_node_init(new_node);
	history_node_set_input(new_node, input);
	if (hist->node_count == 0) {
		new_node->prev_node = hist->tail_node;
		new_node->next_node = hist->head_node;
		hist->tail_node->next_node = new_node;
		hist->head_node->prev_node = new_node;
		hist->node_count = 1;
	} else if (hist->node_count == HISTORY_MAX_NODE_COUNT) {
		temp = hist->tail_node->next_node;
		hist->tail_node->next_node = temp->next_node;
		temp->next_node->prev_node = hist->tail_node;
		history_node_free(temp);

		temp = hist->head_node->prev_node;
		temp->next_node = new_node;
		hist->head_node->prev_node = new_node;
		new_node->prev_node = temp->next_node;
		new_node->next_node = hist->head_node;
	} else {
		temp = hist->head_node->prev_node;
		new_node->prev_node = temp;
		new_node->next_node = hist->head_node;
		temp->next_node = new_node;
		hist->head_node->prev_node = new_node;
		hist->node_count++;
	}
	temp = NULL;
	new_node = NULL;
}

