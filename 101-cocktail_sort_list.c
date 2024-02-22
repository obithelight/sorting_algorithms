#include "sort.h"

void swap_nodes(listint_t **list, listint_t **tail,
		listint_t **shaker, int swap_ahead);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes - Swap a node in a listint_t doubly-linked list
 *              with the node ahead or behind it based on swap_ahead.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 * @swap_ahead: A boolean flag indicating whether to swap with the node ahead.
 */
void swap_nodes(listint_t **list, listint_t **tail,
		listint_t **shaker, int swap_ahead)
{
	listint_t *tmp = swap_ahead ? (*shaker)->next : (*shaker)->prev;

	if (swap_ahead ? ((*shaker)->prev != NULL) : ((*shaker)->next != NULL))
		(swap_ahead ? (*shaker)->prev : (*shaker)->next)->next = tmp;
	else
		*list = tmp;

	if (tmp->next != NULL)
		tmp->next->prev = swap_ahead ? *shaker : tmp;
	else
		*tail = swap_ahead ? *shaker : tmp;

	(swap_ahead ? (*shaker)->next : (*shaker)->prev) = tmp->next;
	tmp->prev = swap_ahead ? (*shaker)->prev : *shaker;

	(swap_ahead ? (*shaker)->prev : *shaker) = tmp;
	tmp->next = swap_ahead ? *shaker : tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	int shaken_not_stirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!shaken_not_stirred)
	{
		shaken_not_stirred = 1;

		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_nodes(list, &tail, &shaker, 1);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}

		for (shaker = shaker->prev; shaker != *list; shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_nodes(list, &tail, &shaker, 0);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
	}
}
