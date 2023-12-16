#include "sort.h"

/**
 * swap_func - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * Return: 0
 */
void swap_func(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_func - Partitions the array for quick sort
 * @array: Array to be sorted
 * @down: Start index of the partition
 * @up: End index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
size_t partition_func(int *array, int down, int up, size_t size)
{
	int pivot = array[up];
	size_t i = down - 1;
	size_t j;

	for (j = down; j < (size_t)up; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_func(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	swap_func(&array[i + 1], &array[up]);
	if (array[i + 1] != array[up])
		print_array(array, size);
	return (i + 1);
}

/**
 * q_sort_recursive - Recursive function to perform Quick sort
 * @array: Array to be sorted
 * @down: Start index of the partition
 * @up: End index of the partition
 * @size: Size of the array
 * Return: 0
 */
void q_sort_recursive(int *array, int down, int up, size_t size)
{
	size_t pivot_ind;

	if (down < up)
	{
		pivot_ind = partition_func(array, down, up, size);

		if (pivot_ind > 1)
		{
			q_sort_recursive(array, down, pivot_ind - 1, size);
		}
		if (up > 1)
		{
			q_sort_recursive(array, pivot_ind + 1, up, size);
		}
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	q_sort_recursive(array, 0, size - 1, size);
}
