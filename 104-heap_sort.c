#include "sort.h"

#define HEAP_PARENT_INDEX(node_index) (((node_index) - 1) / 2)
#define HEAP_LCHILD_INDEX(node_index) (((node_index) * 2) + 1)
#define HEAP_RCHILD_INDEX(node_index) (((node_index) * 2) + 2)

/**
 * pswap - swap elements and print array
 *
 * @array: pointer to the array
 * @size: sizeo of the array
 * @i: index of element to swap
 * @j: index of element to swap
 */
static void pswap(int *array, size_t size, size_t i, size_t j)
{
	array[i] ^= array[j];
	array[j] ^= array[i];
	array[i] ^= array[j];
	print_array(array, size);
}

/**
 * sift_down - repair a max-heap rooted at the parent of valid max-heaps
 * Afua Task
 *
 * @array: pointer to the array
 * @size: size of the array
 * @start: index of the root of the heap to repair
 * @end: index of the last heap element
 */
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t swap = root;
	size_t lchild = 0;
	size_t rchild = 0;

	while (HEAP_LCHILD_INDEX(root) <= end)
	{
		lchild = HEAP_LCHILD_INDEX(root);
		rchild = HEAP_RCHILD_INDEX(root);
		if (array[swap] < array[lchild])
			swap = lchild;
		if (rchild <= end && array[swap] < array[rchild])
			swap = rchild;
		if (swap == root)
			return;
		pswap(array, size, root, swap);
		root = swap;
	}
}

/**
 * heapify - construct a max-heap
 *
 * @array: pointer to the array
 * @size: size of the array
 */
static void heapify(int *array, size_t size)
{
	size_t end = size - 1;
	size_t start = HEAP_PARENT_INDEX(end);

	while (start < end)
		sift_down(array, size, start--, end);
}

/**
 * heap_sort - sort an array in ascending order
 * By Afua
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (array && size)
	{
		heapify(array, size);
		while (end > 0)
		{
			pswap(array, size, 0, end--);
			sift_down(array, size, 0, end);
		}
	}
}
