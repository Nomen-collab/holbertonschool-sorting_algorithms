#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * print_array - Prints an array of integers.
 * 
 * @array: The array to be printed.
 * @size: The number of elements in the array.
 */
void print_array(const int *array, size_t size);

/**
 * print_list - Prints a list of integers (doubly linked list).
 * 
 * @list: The list to be printed.
 */
void print_list(const listint_t *list);

/**
 * listint_t - Data structure for a doubly linked list node.
 */
typedef struct listint_s
{
		const int n;
		struct listint_s *prev;
		struct listint_s *next;
} listint_t;

#endif /* SORT_H */

