#include "sort.h"

/**
 * insertion_sort_list - Performs ascending order on a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current__node;
	listint_t *prev__node;

	current__node = (*list)->next;

	while (current__node != NULL)
	{
		prev__node = current__node->prev;

		while (prev__node != NULL && prev__node->n > current__node->n)
		{

			if (current__node->next != NULL)
				current__node->next->prev = prev__node;

			prev__node->next = current__node->next;
			current__node->next = prev__node;
			current__node->prev = prev__node->prev;

			if (prev__node->prev != NULL)
				prev__node->prev->next = current__node;
			else
				*list = current__node;

			prev__node->prev = current__node;

			print_list(*list);
			prev__node = current__node->prev;
		}

		current__node = current__node->next;
	}
}
