/*
 * File: 106-bitonic_sort.c
 * Auth: osama and belal
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: Array size.
 * @start: Starting index for bitonic block.
 * @seq: Block size in the bitonic sequence.
 * @flow: Sorting direction for the block.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Transforms an integer array into a sequence.
 * @array: Integer array.
 * @size: Array size.
 * @start: Starting index for bitonic block.
 * @seq: Block size in the bitonic sequence.
 * @flow: Sorting direction for the block.
 *
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t coot = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, coot, UP);
		bitonic_seq(array, size, start + coot, coot, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts integers using bitonic sort.
 * @array: Integer array.
 * @size: Array size.
 *
 * Note: Displays array after swaps.
 * Requires size as 2^k, k >= 0.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_seq(array, size, 0, size, UP);
}
