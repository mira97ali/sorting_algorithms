#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm.
 * @arr: The array to be sorted.
 * @len: The size of the array.
 */
void bubble_sort(int *arr, size_t len)
{
	size_t idx_outer, idx_inner;
	int tmp;
	int did_swap;

	for (idx_outer = 0; idx_outer < len - 1; idx_outer++)
	{
		did_swap = 0;

		for (idx_inner = 0; idx_inner < len - idx_outer - 1; idx_inner++)
		{
			if (arr[idx_inner] > arr[idx_inner + 1])
			{
				tmp = arr[idx_inner];
				arr[idx_inner] = arr[idx_inner + 1];
				arr[idx_inner + 1] = tmp;
				did_swap = 1;
				print_array(arr, len);
			}
		}

		if (did_swap == 0)
			break;
	}
}

