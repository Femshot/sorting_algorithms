#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, xch;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		xch = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				xch = 1;
			}
		}
		if (xch == 0)
			break;
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
