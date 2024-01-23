#include "sort.h"

/**
 * custom_swap - Exchange two integers within an array.
 * @first_elem: The initial int for the exchange.
 * @second_elem: The subsequent int.
 */

void custom_swap(int *first_elem, int *second_elem)
{
	int temp;

	temp = *first_elem;
	*first_elem = *second_elem;
	*second_elem = temp;
}

/**
 * custom_partition - Organize a segment of an integer array using a custom
 *                     partition scheme (last element as pivot).
 * @arr: The array of ints.
 * @size: The size of the arr.
 * @left_idx: The initial idx of the subset to order.
 * @right_idx: The final index.
 *
 * Return: The ult partition index.
 */

int custom_partition(int *arr, size_t size, int left_idx, int right_idx)
{
	int *pivot, above, below;

	pivot = arr + right_idx;
	for (above = below = left_idx; below < right_idx; below++)
	{
		if (arr[below] < *pivot)
		{
			if (above < below)
			{
				custom_swap(arr + below, arr + above);
				print_array(arr, size);
			}
			above++;
		}
	}

	if (arr[above] > *pivot)
	{
		custom_swap(arr + above, pivot);
		print_array(arr, size);
	}

	return (above);
}

/**
 * custom_sort - Implement a recursive sorting algorithm.
 * @arr: An array of ints.
 * @size: The size of the arr.
 * @left_idx: The initial idx of the array.
 * @right_idx: The ending index of the array.
 *
 * Description: Utilizes a custom partition scheme.
 */

void custom_sort(int *arr, size_t size, int left_idx, int right_idx)
{
	int part;

	if (right_idx - left_idx > 0)
	{
		part = custom_partition(arr, size, left_idx, right_idx);
		custom_sort(arr, size, left_idx, part - 1);
		custom_sort(arr, size, part + 1, right_idx);
	}
}

/**
 * quick_sort - Arranges an array of integers.
 * @array: An array.
 * @size: The size of the array.
 *
 * Description: the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	custom_sort(array, size, 0, size - 1);
}
