#include "binary_trees.h"

/**
 * array_to_heap - constructs a Max Binary Heap tree from a given array
 * @array: a pointer to the first element of the array.
 * @size: the total number of elements in the array
 *
 * Return: a pointer to the root node of the newly formed Binary Heap.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (heap_insert(&root, array[i]) == NULL)
			return (NULL);
	}

	return (root);
}
