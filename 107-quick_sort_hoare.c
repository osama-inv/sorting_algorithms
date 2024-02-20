#include "sort.h"

void int_swap(int *n, int *m);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * int_swap - a function that swaps two integers in an array
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
 * hoare_partition - a function that Orders a subset of an array of integers
 *	according to the hoare partition scheme.
 *
 * @array: is the array of integers.
 * @size: is the size of the array.
 * @left: is the starting index of the subset to order.
 * @right: is the ending index of the subset to order.
 *
 * Description: it uses the last element of the partition as the pivot,
 *	it Prints the array after each swap of two elements
 *
 * Return: the final partition index
*/

int hoare_partition(int *array, size_t size, int left, int right)
{
	int piv, abv, bel;

	piv = array[right];

	for (abv = left - 1, bel = right + 1; abv < bel;)
	{
		do {
			abv++;
		} while (array[abv] < piv);
		do {
			bel--;
		} while (array[bel] > piv);

		if (abv < bel)
		{
			int_swap(array + abv, array + bel);
			print_array(array, size);
		}
	}
	return (abv);
}

/**
 * hoare_sort - a function that implement the quicksort algorithm through
 *	recursion
 *
 * @array: is the array of integers to sort
 * @size: is the size of the array
 * @left: is the starting index of the array partition to order
 * @right: is the ending index of the array partition to order
 *
 * Description: it uses the Hoare partition scheme
 *
 * Return: void
*/

void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - a function that Sorts an array of integers in ascending
 *	order using the quicksort algorithm
 *
 * @array: is the array of integers
 * @size: is the size of the array
 *
 * Description: it uses the Hoare partition scheme
 *	as it Prints the array after each swap of two elements
 *
 * Return: void
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	hoare_sort(array, size, 0, size - 1);
}
