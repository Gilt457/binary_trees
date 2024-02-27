#include "binary_trees.h"

/**
 * binary_tree_size - calculates the total number of nodes in a binary tree
 * @tree: a pointer to the root node of the tree whose size is to be determined
 *
 * Return: the total count of nodes in the binary tree. If tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_size(tree->left) +
			1 + binary_tree_size(tree->right));
}
