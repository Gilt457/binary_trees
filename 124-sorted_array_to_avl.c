#include "binary_trees.h"

/**
 * aux_sort - Recursive function to build an AVL tree from a sorted array
 * @parent: Parent node of the current subtree
 * @array: Sorted array
 * @begin: Starting index of the current subarray
 * @last: Ending index of the current subarray
 * Return: Pointer to the root node of the current subtree, or NULL on failure
 */
avl_t *aux_sort(avl_t *parent, int *array, size_t begin, size_t last)
{
	size_t mid;
	avl_t *root;
	binary_tree_t *aux;

	if (begin > last)
		return (NULL);

	mid = (begin + last) / 2;
	aux = binary_tree_node(parent, array[mid]);
	if (!aux)
		return (NULL);

	root = (avl_t *)aux;
	root->parent = parent;
	root->left = aux_sort(root, array, begin, mid - 1);
	root->right = aux_sort(root, array, mid + 1, last);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (aux_sort(NULL, array, 0, size - 1));
}
