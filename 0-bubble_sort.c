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
 * bubble_sort - Sort an array in ascending order.
 * @array: An array to sort.
 * @size: The size of it.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (sorted == false)
	{
		sorted = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		length--;
	}
}
