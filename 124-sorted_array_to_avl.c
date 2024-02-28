#include "binary_trees.h"

/**
 * build_tree - Constructs an AVL tree from an ordered array
 * @array: Pointer to the array's first element that will be transformed
 * @start: The index where the segment of the array to be transformed begins
 * @end: The index where the segment of the array to be transformed ends
 *
 * Return: Pointer to the root node of the AVL tree that was created.
 */
avl_t *build_tree(int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = array[mid];
	node->parent = NULL;
	node->left = build_tree(array, start, mid - 1);
	node->right = build_tree(array, mid + 1, end);

	if (node->left)
		node->left->parent = node;
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * sorted_array_to_avl - Constructs an AVL tree from an ordered array
 * @array: Pointer to the array's first element that will be transformed
 * @size: The number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree that was created.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (build_tree(array, 0, size - 1));
}
