#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *					Selection sort algorithm
 * @array: Array to sort
 * @size: Size of arrary
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = (i + 1); j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - Swaps two elements
 * @a: Address of first element
 * @b: Address of second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
