#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: The array being sorted.
 * @size: Size of the array.
 * Author: Amira.
 */
void selection_sort(int *array, size_t size)
{
	size_t index_i, index_j, min_index;
	int temporary;

	for (index_i = 0; index_i < size - 1; index_i++)
	{
		min_index = index_i;

		for (index_j = index_i + 1; index_j < size; index_j++)
		{
			if (array[index_j] < array[min_index])
				min_index = index_j;
		}

		if (min_index != index_i)
		{
			temporary = array[index_i];
			array[index_i] = array[min_index];
			array[min_index] = temporary;
			print_array(array, size);
		}
	}
}
