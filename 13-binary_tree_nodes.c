#include "binary_trees.h"

/**
 * binary_tree_nodes - This function counts binary tree nodes.
 * @tree: This points to the tree's root node for node counting.
 *
 * Return: The function returns the number of binary tree nodes.
 *         If the tree is NULL, the function returns 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL || tree->right != NULL)
	{
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	}

	return (0);
}
