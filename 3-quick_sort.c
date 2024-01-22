#include "sort.h"

/**
 * swap - Swaps two ints in an array
 * @x: First int
 * @y: Second int
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @arr: Array to be partitioned
 * @low_idx: Starting ind of the partition
 * @high_idx: Ending ind of the partition
 * @arr_size: Size of the array
 *
 * Return: Index of the pivot
 */

size_t lomuto_partition(
	int *arr, ssize_t low_idx, ssize_t high_idx, size_t arr_size)
{
	int pivot = arr[high_idx];
	ssize_t i = low_idx - 1, j;

	for (j = low_idx; j <= high_idx - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, arr_size);
		}
	}
	swap(&arr[i + 1], &arr[high_idx]);
	print_array(arr, arr_size);

	return (i + 1);
}

/**
 * quicksort - perform Quick sort
 * @arr: Array to be sorted
 * @low_idx: Starting index of the partition
 * @high_idx: Ending index of the partition
 * @arr_size: Size of the array
 */

void quicksort(int *arr, ssize_t low_idx, ssize_t high_idx, size_t arr_size)
{
	if (low_idx < high_idx)
	{
		ssize_t pi = lomuto_partition(arr, low_idx, high_idx, arr_size);

		quicksort(arr, low_idx, pi - 1, arr_size);
		quicksort(arr, pi + 1, high_idx, arr_size);
	}
}

/**
 * quick_sort - Sorts an array of integers
 * @arr: Array to be sorted
 * @arr_size: Size of the array
 */

void quick_sort(int *arr, size_t arr_size)
{
	if (arr == NULL || arr_size < 2)
		return;

	quicksort(arr, 0, arr_size - 1, arr_size);
}
