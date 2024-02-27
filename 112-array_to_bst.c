#include "binary_trees.h"

/**
 * array_to_bst - Constructs a Binary Search Tree (BST) using an array.
 *
 * @array: A pointer to the initial element of the array to be used.
 * @size: The count of elements in the array
 *
 * Return: A pointer to the root node of the formed BST, or NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t outer, inner;

	if (array == NULL)
		return (NULL);

	for (outer = 0; outer < size; outer++)
	{
		for (inner = 0; inner < outer; inner++)
		{
			if (array[inner] == array[outer])
				break;
		}
		if (inner == outer)
		{
			if (bst_insert(&tree, array[outer]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
