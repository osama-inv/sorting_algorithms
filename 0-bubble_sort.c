#include "sort.h"

/**
 * swap_ints - Exchanges the positions of two integers.
 * @a: The initial integer to be exchanged.
 * @b: The other integer to be exchanged.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Orders from smallest to largest.
 * @array: The collection of integers to be ordered.
 * @size: The number of elements in the array.
 *
 * Description: Displays the array following each exchange.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, lon = size;
	bool bubble = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (bubble == false)
	{
		bubble = true;
		for (i = 0; i < lon - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		lon--;
	}
}
