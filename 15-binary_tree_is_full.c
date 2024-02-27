#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: If tree is NULL or if the tree is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*
	 * A full binary tree has 0 or 2 children. So, we check if it's a leaf
	 * node or if both children are present.
	 */
	if ((tree->left == NULL && tree->right == NULL) ||
		(tree->left != NULL && tree->right != NULL))
		return ((binary_tree_is_full(tree->left)) &&
			(binary_tree_is_full(tree->right)));

	return (0);
}
