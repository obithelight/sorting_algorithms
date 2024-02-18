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
