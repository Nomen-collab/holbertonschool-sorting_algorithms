#include <stdio.h>
#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void _swap(int *array, int i, int j, int size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * _swap - swaps two values in an array
 *
 * @array: data to sort
 * @i: first value
 * @j: second value
 * @size: size of data
 *
 * Return: No Return
 */
void _swap(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - sorts a partition of data in relation to a pivot
 *
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of data
 *
 * Return: New Pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i = min, j, pivot  = array[max];

	for (j = min; j <= max; j++)
	{
		if (array[j] < pivot)
		{
			_swap(array, i, j, size);
			i++;
		}

	}
	_swap(array, i, max, size);

	return (i);
}


/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort
 *
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}
