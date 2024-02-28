#include "binary_trees.h"

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_tree(avl_t *parent, int *array, int start, int end);

/**
 * sorted_array_to_avl - Converts an array into an AVL tree.
 *
 * @array: A pointer to the first element of the array to be transformed.
 * @size: The total number of elements in the array.
 *
 * Return: A pointer to the root node of the newly created AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	/* Check if the array is empty or null */
	if (array == NULL || size == 0)
		return (NULL);
	/* Call the helper function to create the tree */
	return (create_tree(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * create_tree - Constructs the tree using the middle element of the array.
 *
 * @parent: The parent node of the node to be created.
 * @array: The sorted array.
 * @start: The starting position of the array.
 * @end: The ending position of the array.
 *
 * Return: The created tree.
 */
avl_t *create_tree(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	/* Check if the start index is less than or equal to the end index */
	if (start <= end)
	{
		/* Calculate the middle index */
		mid = (start + end) / 2;
		/* Create a new node with the middle element of the array */
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		/* Check if the node creation was successful */
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		/* Recursively create the left and right subtrees */
		root->left = create_tree(root, array, start, mid - 1);
		root->right = create_tree(root, array, mid + 1, end);
		/* Return the root of the created tree */
		return (root);
	}
	/* If the start index is greater than the end index, return NULL */
	return (NULL);
}
