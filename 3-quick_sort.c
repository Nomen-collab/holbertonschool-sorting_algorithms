#include "sort.h"

/**
 * partition - Partitions the array for quicksort
 *
 * @array: The array to partition
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 *
 * Return: The partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_rec - Recursively sorts the array using quicksort
 *
 * @array: The array to sort
 * @low: The starting index
 * @high: The ending index
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int start_index, int end_index, size_t size)
{
	if (start_index < end_index)
	{
		int partition_index = partition(array, start_index, end_index, size);
		quick_sort_rec(array, start_index, partition_index - 1, size);
		quick_sort_rec(array, partition_index + 1, end_index, size);
	}
	}

/**
 * quick_sort - Sorts an array of integers
 * in ascending order using Quick sort
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
