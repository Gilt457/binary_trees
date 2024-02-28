#include "binary_trees.h"

/**
 * height - Calculates binary tree height
 * @tree: Pointer to the root node of the tree whose height is to be computed
 * Return: Tree height
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
 * is_avl_helper - Verifies if a binary tree is a valid AVL Tree
 * @tree: A tree root node pointer to verify.
 * @lo: The smallest possible value for nodes in the tree
 * @hi: The largest possible value for nodes in the tree
 * Return: Tree is genuine AVL tree if 1; otherwise 0
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

	return (is_avl_helper(tree->left, lo, tree->n - 1) &&
		is_avl_helper(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_avl - Verifies if a binary tree is a valid AVL Tree
 * @tree: A tree root node pointer to verify
 * Return: Tree is genuine AVL Tree if 1; otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
