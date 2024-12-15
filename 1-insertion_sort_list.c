#include "sort.h"

void swap_nodes(listint_t **current_node, listint_t **list_head)
{
	listint_t *node_to_swap = *current_node, *next_node, *previous_node;

	if (!(*current_node)->prev)
		*list_head = (*current_node)->next;

	node_to_swap = previous_node = *current_node;
	next_node = node_to_swap->next;

	node_to_swap->next = next_node->next;
	previous_node = node_to_swap->prev;
	node_to_swap->prev = next_node;
	next_node->next = node_to_swap;
	next_node->prev = previous_node;

	if (next_node->prev)
		next_node->prev->next = next_node;

	if (node_to_swap->next)
		node_to_swap->next->prev = node_to_swap;

	*current_node = next_node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 *
 * Return: No Return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = *list, *temp_node, *aux_node;

	if (!current_node || (!(current_node->prev) && !(current_node->next)))
		return;

	while (current_node && current_node->next)
	{
		if (current_node->n > current_node->next->n)
		{
			aux_node = current_node;

			swap_nodes(&aux_node, list);
			print_list(*list);

			while (aux_node->prev && aux_node->prev->n > aux_node->n)
			{
				temp_node = aux_node->prev;
				swap_nodes(&temp_node, list);
				print_list(*list);
			}
		}
		else
		{
			current_node = current_node->next;
		}
	}
}
