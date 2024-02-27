#include "binary_trees.h"

/**
 * binary_tree_leaves - This method counts binary tree leaf nodes.
 * @tree: This is the root node of the tree whose leaf nodes we count.
 *
 * Return: The function returns 0 if the tree is NULL.
 * A NULL pointer does not count as a leaf node.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
