#include "sort.h"

/**
 * find_max - a function that finds the maximum value in an array of integers
 *
 * @array: is the array of integers
 * @size: is the size of the array
 *
 * Return: the maximum integer found in the array
*/

int find_max(int *array, int size)
{
	int n, n_max;

	for (n_max = array[0], n = 1; n < size; n++)
	{
		if (array[n] > n_max)
		{
			n_max = array[n];
		}
	}
	return (n_max);
}

/**
 * counting_sort - a function that Sorts an array of integers in ascending
 *	order using the counting sort algorithm
 *
 * @array: is the array of integers
 * @size: is the size of the array
 *
 * Description: is prints the counting array after setting it up
 *
 * Return: void
*/

void counting_sort(int *array, size_t size)
{
	int n, n_max, *n_cont, *n_sort;

	if (array == NULL || size < 2)
		return;
	n_sort = malloc(sizeof(int) * size);

	if (n_sort == NULL)
		return;
	n_max = find_max(array, size);
	n_cont = malloc(sizeof(int) * (n_max + 1));
	if (n_cont == NULL)
	{
		free(n_sort);
		return;
	}
	for (n = 0; n < (n_max + 1); n++)
	{
		n_cont[n] = 0;
	}
	for (n = 0; n < (int)size; n++)
	{
		n_cont[array[n]] += 1;
	}
	for (n = 0; n < (n_max + 1); n++)
	{
		n_cont[n] += n_cont[n - 1];
	}
	print_array(n_cont, n_max + 1);

	for (n = 0; n < (int)size; n++)
	{
		n_sort[n_cont[array[n]] - 1] = array[n];
		n_cont[array[n]] -= 1;
	}
	for (n = 0; n < (int)size; n++)
	{
		array[n] = n_sort[n];
	}
	free(n_sort);
	free(n_cont);
}
