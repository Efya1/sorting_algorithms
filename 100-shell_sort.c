#include "sort.h"

/**
 * shell_sort - shell Sort Algrithme using Knuth sequence
 * @array: Array to be Sorted
 * @size:size of the array
 * Afua task
 * Return:Sorted Array (void)
 */
void shell_sort(int *array, size_t size)
{
	int n = 1, x, y;
	int tmp;

	if (!array || !size || size < 2)
		return;
	while (n < (int)size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (x = n; x < (int)size; x++)
		{
			tmp = array[x];
			y = x;
			while (y > (n - 1) && array[y - n] >= tmp)
			{
				array[y] = array[y - n];
				y -= n;
			}
			array[y] = tmp;
		}
		n = n / 3;
		print_array(array, size);
	}
}
