#include "sort.h"

/**
 * node_swap - function that Swaps two nodes in a doubly-linked list
 *
 * @h: is a pointer to the head of the doubly-linked list
 * @n: is a pointer to the first node to swap
 * @m: is the the second node to swap
 *
 * Return: nothing
*/

void node_swap(listint_t **h, listint_t **n, listint_t *m)
{
	(*n)->next = m->next;

	if (m->next != NULL)
	{
		m->next->prev = *n;
	}
	m->prev = (*n)->prev;
	m->next = *n;

	if ((*n)->prev != NULL)
	{
		(*n)->prev->next = m;
	}
	else
	{
		*h = m;
	}
	(*n)->prev = m;
	*n = m->prev;
}

/**
 * insertion_sort_list - function that Sorts a doubly linked list of integers,
 *	using the insertion sort algorithm
 *
 * @list: is a pointer to the head of a doubly-linked list of integers.
 *
 * Description: it prints the list after each swap
 *
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *ins, *itr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		ins = itr->prev;
		while (ins != NULL && itr->n < ins->n)
		{
			node_swap(list, &ins, itr);
			print_list((const listint_t *)*list);
		}
	}
}
