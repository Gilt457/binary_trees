#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * @lo: The minimum possible value for nodes in the tree
 * @hi: The maximum possible value for nodes in the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	int lhgt, rhgt, diff;

	if (tree == NULL)
		return (1);

	if (tree->n < lo || tree->n > hi)
		return (0);

	lhgt = height(tree->left);
	rhgt = height(tree->right);

	diff = lhgt - rhgt;

	if (diff > 1 || diff < -1)
		return (0);

	return (is_avl_helper(tree->left, lo, tree->n - 1) && is_avl_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
