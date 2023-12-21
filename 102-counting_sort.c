#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int max = 0, i;

	if (!array || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);

	if (!count || !output)
	{
		free(count);
		free(output);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}