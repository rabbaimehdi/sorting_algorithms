#include "sort.h"

/**
 * swap - Swap two integers.
 * @a: int 1.
 * @b: int 2.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *
 * @array: An array.
 * @size: The size of it.
 *
 * Description: Prints the array after swapping.
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small = array + i;
		for (j = i + 1; j < size; j++)
			small = (array[j] < *small) ? (array + j) : small;

		if ((array + i) != small)
		{
			swap_ints(array + i, small);
			print_array(array, size);
		}
	}
}
