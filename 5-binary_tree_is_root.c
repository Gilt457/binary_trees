#include "binary_trees.h"

/**
 * binary_tree_is_root - determines if a specified node is the root of a tree
 * @node: the node under examination
 * Return: returns 1 if the node is the root, otherwise returns 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);
	return (0);
}
