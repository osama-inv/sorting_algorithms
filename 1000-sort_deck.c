#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Evaluates the difference between two strings.
 * @s1: Initial string for comparison.
 * @s2: Second string for comparison.
 *
 * Return: Positive value if s1 is lexicographically
 * greater than s2,
 *         0 if s1 is equal to s2,
 *         Negative value if s1 is less than s2.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	return (0);
}

/**
 * get_value - Retrieves the value associated with a card.
 * @card: Pointer of type deck_node_t.
 *
 * Return: The card's numeric value.
 */

char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Orders a deck of cards.
 * @deck: Pointer to the starting node of a list.
 */

void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *itir, *insert, *temp;

	for (itir = (*deck)->next; itir != NULL; itir = temp)
	{
		temp = itir->next;
		insert = itir->prev;
		while (insert != NULL && insert->card->kind > itir->card->kind)
		{
			insert->next = itir->next;
			if (itir->next != NULL)
				itir->next->prev = insert;
			itir->prev = insert->prev;
			itir->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = itir;
			else
				*deck = itir;
			insert->prev = itir;
			insert = itir->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards.
 * @deck: A pointer.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itir, *insert, *tmp;

	for (itir = (*deck)->next; itir != NULL; itir = tmp)
	{
		tmp = itir->next;
		insert = itir->prev;
		while (insert != NULL &&
		       insert->card->kind == itir->card->kind &&
		       get_value(insert) > get_value(itir))
		{
			insert->next = itir->next;
			if (itir->next != NULL)
				itir->next->prev = insert;
			itir->prev = insert->prev;
			itir->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = itir;
			else
				*deck = itir;
			insert->prev = itir;
			insert = itir->prev;
		}
	}
}

/**
 * sort_deck - Sort a cards.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
