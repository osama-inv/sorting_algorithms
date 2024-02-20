#include "sort.h"

/**
 * int_swap - a function that Swaps two integers in an array
 *
 * @n: is the first integer to swap
 * @m: is the second integer to swap
 *
 * Return: void
*/

void int_swap(int *n, int *m)
{
	int temp;

	temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * selection_sort - function that Sorts an array of integers in ascending order
 *	using the selection sort algorithm
 *
 * @array: is an array of integers
 * @size: is the size of the array
 *
 * Description: it prints the array after each swap made
 *
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
	int *ptr;
	size_t i, n;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		ptr = array + i;
		for (n = i + 1; n < size; n++)
		{
			ptr = (array[n] < *ptr) ? (array + n) : ptr;
		}
		if ((array + i) != ptr)
		{
			int_swap(array + i, ptr);
			print_array(array, size);
		}
	}
}
