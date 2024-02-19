#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Finds the highest integer in an integer array.
 * @array: Integer array.
 * @size: Array size.
 *
 * Return: Highest value in the array.
 */

int get_max(int *array, int size)
{
	int maxint, i;

	for (maxint = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxint)
			maxint = array[i];
	}

	return (maxint);
}

/**
 * radix_counting_sort - Sorts integers by significant
 * digit using counting sort.
 * @array: Integer array.
 * @size: Array size.
 * @sig: Digit to sort by.
 * @buff: Temporary storage for sorted elements.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		count[(array[i] / sig) % 10] += 1;
	}

	for (i = 0; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Ascendingly sorts an integer array.
 * @array: Integer array.
 * @size: Array size.
 *
 * Description: Uses LSD radix sort,
 * displaying array after each digit iteration.
 */
void radix_sort(int *array, size_t size)
{
	int maxint, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxint = get_max(array, size);
	for (sig = 1; maxint / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
