#include "sort.h"

/**
 * counting_sort - func to sort
 * @array: The array to be sorted.
 * @size: The size of the array.
 * Return: -
 */
void counting_sort(int *array, size_t size)
{
	int *count, *new, max = 0, i = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	count = malloc(sizeof(int) * max + 1);

	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] = count[i - 1] + count[i];

	new = malloc(sizeof(int) * size + 1);
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		new[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = new[i];
}
