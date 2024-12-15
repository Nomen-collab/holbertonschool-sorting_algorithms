#include <stdio.h>

/**
 * print_array_b - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array_b(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * selection_sort - Sorts an array of integers
 * in ascending order using Selection sort
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t current_index, next_index, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size - 1; ++current_index)
	{
		/* Find the minimum element in the unsorted part of the array */
		min_index = current_index;
		for (next_index = current_index + 1; next_index < size; ++next_index)
		{
			if (array[next_index] < array[min_index])
				min_index = next_index;
		}

		/* Swap the found minimum element with the first element */
		if (min_index != current_index)
		{
			temp = array[current_index];
			array[current_index] = array[min_index];
			array[min_index] = temp;
			print_array_b(array, size);
		}
	}
}
