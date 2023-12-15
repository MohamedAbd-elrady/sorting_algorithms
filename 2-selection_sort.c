#include "sort.h"
/**
 * selection_sort - sorts all selecty like
 * @array: array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int indx = 0, min, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				indx = j;
				continue;
			}
		}

		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[indx] = temp;
			print_array(array, size);
		}
	}
}
