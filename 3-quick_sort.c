#include "sort.h"

/**
 * swap_func - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
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
int partition_func(int *array, int down, int up, size_t size)
{
	int pivot = array[up];
	int i = down - 1;
	int j;

	for (j = down; j < up; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_func(&array[i], &array[j]);
		}
	}

	swap_func(&array[i + 1], &array[up]);
	print_array(array, size);
	return (i + 1);
}

/**
 * q_sort_recursive - Recursive function to perform Quick sort
 * @array: Array to be sorted
 * @down: Start index of the partition
 * @up: End index of the partition
 * @size: Size of the array
 */
void q_sort_recursive(int *array, int down, int up, size_t size)
{
	if (down < up)
	{
		int pivot_index = partition_func(array, down, up, size);

		if (pivot_index != down)
		{
			q_sort_recursive(array, down, pivot_index - 1, size);
		}

		q_sort_recursive(array, pivot_index + 1, up, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	q_sort_recursive(array, 0, size - 1, size);
}
