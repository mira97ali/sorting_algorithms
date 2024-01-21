#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


/** Given Functions */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/** My Functions */
void bubble_sort(int *arr, size_t len);

#endif
