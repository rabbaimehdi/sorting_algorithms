#include "sort.h"
/**
 * i_swap - function that swap two element of an array
 * @i: the first element to swap
 * @j: the second element to swap 
 */
void i_swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
/**
 * partition - function that sorts an array
 * @array: array of intergers
 * @i_low: start indice 
 * @i_high: end indice 
 * @size: size of the array
 * Return: final indice
 */
int partition(int *array, int i_low, int i_high, size_t size)
{
	int a, b;
	int pivot;

	pivot = array[i_high];
	b = i_low;

	for (a = i_high; a <= i_high - 1; a++)
	{
		if (array[a] < pivot)
		{
			if (a != b && array[a] != array[b])
			{
				i_swap(&array[b], &array[a]);
				print_array(array, size);
			}
			b++;
		}
	}
	if (b != i_high && array[b] != array[i_high])
	{
		i_swap(&array[b], &array[i_high]);
		print_array(array, size);
	}
	return (b);
}
/**
 * recursion - function that sorts the array
 * @array: array to sort
 * @i_low: start indice 
 * @i_high: end indice
 * @size: size of the array
 * Return: nothing
 */
void recursion(int *array, int i_low, int i_high, size_t size)
{
	int b;

	if (i_low < i_high)
	{
		b = partition(array, i_low, i_high, size);
		recursion(array, i_low, b - 1, size);
		recursion(array, b + 1, i_high, size);
	}
}
/**
 * quick_sort - function that sorts an array using quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursion(array, 0, size - 1, size);
}
