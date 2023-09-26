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
	int *pivot;

	pivot = array + i_high;
	for (a = b = i_low; b <= i_high - 1; b++)
	{
		if (array[b] < *pivot)
		{
			if (a < b)
			{
				i_swap(&array[b], &array[a]);
				print_array(array, size);
			}
			a++;
		}
	}
	if (array[a] > *pivot)
	{
		i_swap(&array[a], pivot);
		print_array(array, size);
	}
	return (a);
}
/**
 * sort_i - function that sorts the array
 * @array: array to sort
 * @i_low: start indice 
 * @i_high: end indice
 * @size: size of the array
 * Return: nothing
 */
void sort_i(int *array, int i_low, int i_high, size_t size)
{
	int b;

	if (i_low < i_high)
	{
		b = partition(array, i_low, i_high, size);
		sort_i(array, i_low, b - 1, size);
		sort_i(array, b + 1, i_high, size);
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
	sort_i(array, 0, size - 1, size);
}
