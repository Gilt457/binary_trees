#include "binary_trees.h"

/**
 * binary_tree_uncle - identifies the uncle of a given node
 * @node: the node whose uncle is to be determined
 *
 * Return: a pointer to the node representing the uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
