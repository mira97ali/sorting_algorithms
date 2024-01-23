#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** Given Functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/** My Functions */
void custom_swap(int *first_elem, int *second_elem);
int custom_partition(int *arr, size_t size, int left_idx, int right_idx);
void custom_sort(int *arr, size_t size, int left_idx, int right_idx);
void custom_quicksort(int *arr, size_t size);

#endif
