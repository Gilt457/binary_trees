#include "binary_trees.h"

/**
 * bst_search - This function performs a search operation.
 * @tree: This is a pointer to the root node of the BST.
 * @value: This is the value that we are looking for in tree.
 *
 * Return: This function returns a pointer to the node.
 *         If the tree is NULL or if the search value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n < value)
		return (bst_search(tree->right, value));
	else if (tree->n > value)
		return (bst_search(tree->left, value));
	else
		return ((bst_t *)tree);
}
