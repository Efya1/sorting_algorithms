#include "sort.h"

/**
 *bubble_sort - sorts an array of integers in ascending orde
 *@array: This is  the array to be sort
 *By Afua Asubonteng
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int n;

	if (size < 2)
		return;
	for (y = 0; y < size - 1; y++)
	{
		for (x = 0; x < size - y - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				n = array[x];
				array[x] = array[x + 1];
				array[x + 1] = n;
				print_array(array, size);
			}
		}
	}
}
