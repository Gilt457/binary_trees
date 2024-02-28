#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * @lo: lower limit
 * @hi: upper limit
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	int height_left;
	int height_right;

	if (tree == NULL)
		return (1);

	if (tree->n <= lo || tree->n >= hi)
		return (0);

	height_left = height(tree->left);
	height_right = height(tree->right);

	if (abs(height_left - height_right) > 1)
		return (0);

	return (is_avl_helper(tree->left, lo, tree->n) &&
			is_avl_helper(tree->right, tree->n, hi));
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = height(tree->left);
	height_r = height(tree->right);

	return (MAX(height_l, height_r) + 1);
}
