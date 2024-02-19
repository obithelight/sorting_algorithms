#include "sort.h"

/**
 * swap_func - swaps the position of two elements
 * @left: the first selected element to be swapped
 * @right: the second selected element to be swapped
 */
void swap_func(int *left, int *right)
{
        int temp;

        temp = *left;
        *left = *right;
        *right = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 *		using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b, swapped;

	for (a = 0; a < size - 1; a++)
	{
		swapped = 0;
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				swap_func(&array[b], &array[b + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
