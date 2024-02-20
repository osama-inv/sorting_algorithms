#include "sort.h"

/**
 * int_swap - function that Swaps two integers in an array
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
 * shell_sort - a function that Sorts an array of integers in ascendingorder
 *	using the shell sort algorithm
 *
 * @array: is the array of integers
 * @size: is the size of the array
 *
 * Description: it uses the Knuth interval sequence
 *
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t dif, n1, n2;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (dif = 1; dif < (size / 3);)
	{
		dif = dif * 3 + 1;
	}
	for (; dif >= 1; dif /= 3)
	{
		for (n1 = dif; n1 < size; n1++)
		{
			n2 = n1;
			while (n2 >= dif && array[n2 - dif] > array[n2])
			{
				int_swap(array + n2, array + (n2 - dif));
				n2 = n2 - dif;
			}
		}
		print_array(array, size);
	}
}
