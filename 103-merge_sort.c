#include "sort.h"

/* Function prototypes */
void merge_sort_recursive(int *array, size_t size);
void merge_arrays(int *left, size_t left_size, int *right, size_t right_size);
void copy_merged_array(int *destination, int *source, size_t size);

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursively splits and merges the array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (size < 2)
	{
		return;
	}

	mid = size / 2;

	left = array;
	right = array + mid;

	printf("Merging...\n[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);

	printf("[Done]: ");
	merge_arrays(left, mid, right, size - mid);
	print_array(left, size);
}

/**
 * merge_arrays - Merges two arrays into one.
 * @left: The left array.
 * @left_size: The size of the left array.
 * @right: The right array.
 * @right_size: The size of the right array.
 */
void merge_arrays(int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i, j, k;
	size_t merged_size = left_size + right_size;
	int *merged = malloc(merged_size * sizeof(int));

	if (merged == NULL)
	{
		return;
	}

	i = j = k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			merged[k++] = left[i++];
		}
		else
		{
			merged[k++] = right[j++];
		}
	}

	while (i < left_size)
	{
		merged[k++] = left[i++];
	}

	while (j < right_size)
	{
		merged[k++] = right[j++];
	}

	copy_merged_array(left, merged, merged_size);
	free(merged);
}

/**
 * copy_merged_array - Copies merged array back to the original array.
 * @destination: The destination array.
 * @source: The source array.
 * @size: The size of the arrays.
 */
void copy_merged_array(int *destination, int *source, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
}
