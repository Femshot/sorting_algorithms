#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *				Quick sort algorithm
 * @array: Array to be sorted
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, (size - 1), size);
}

/**
 * quickSort - Sorts an array of integers in ascending order using the
 *			   Quick sort algorithm
 * @arr: Array to be sorted
 * @low: Start index of array
 * @high: End index of array
 * @size: Size of array
 */
void quickSort(int arr[], int low, int high, int size)
{
	int pat;

	if (low < high)
	{
		pat = partition(arr, low, high, size);
		quickSort(arr, low, pat - 1, size);
		quickSort(arr, pat + 1, high, size);
	}

}

/**
 * partition - Splits pivot pertitions between lower values and higher values
 * @arr: Array to be sorted
 * @low: Start index of array
 * @high: End index of array
 * @size: Size of original array
 *
 * Return: Index of partition
 */
int partition(int arr[], int low, int high, int size)
{
	int pivot = arr[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			if (arr[i] != arr[j])
				print_array(arr, size);
		}
	}
	if (arr[i + 1] != arr[high])
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two elements
 * @a: Address of first element
 * @b: Address of second element
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
