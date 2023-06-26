#include "sort.h"


/**
 * counting_sort - Sorts an array using Counting Sort Algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *output, i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(*count) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i < (int)size; i++) /*Store the count of each element*/
		count[array[i]]++;
	for (i = 1; i <= max; i++) /*Store cummulative count of each array*/
		count[i] += count[i - 1];
	print_array(count, (max + 1));

	output = malloc(sizeof(*output) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
