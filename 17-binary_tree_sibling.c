#include "binary_trees.h"

/**
 * binary_tree_sibling - identifies the sibling of a given node
 * @node: the node whose sibling is to be determined
 *
 * Return: pointer to the sibling of the input node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
