#include "binary_trees.h"

/**
 * bst_helper - a function that helps to verify if a binary tree.
 * @tree: a pointer to the root node of the tree to verify
 * @min: a pointer to the node with the smallest value in the tree
 * @max: a pointer to the node with the largest value in the tree
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int bst_helper(const binary_tree_t *tree, const binary_tree_t *min,
	       const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= min->n)
		return (0);

	if (max != NULL && tree->n >= max->n)
		return (0);

	return (bst_helper(tree->left, min, tree) &&
		bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree.
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, NULL, NULL));
}
