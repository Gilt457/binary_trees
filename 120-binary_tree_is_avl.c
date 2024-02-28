#include "binary_trees.h"

int is_avl_tree(const binary_tree_t *t);
int avl_helper(const binary_tree_t *t, int min_val, int max_val);
size_t calculate_height(const binary_tree_t *t);

/**
 * is_avl_tree - Checks if a binary tree is a valid AVL Tree.
 *
 * @t: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int is_avl_tree(const binary_tree_t *t)
{
	if (t == NULL)
		return (0);
	return (avl_helper(t, INT_MIN, INT_MAX));
}

/**
 * avl_helper - Checks if a binary tree is a valid AVL tree.
 * @t: A pointer to the root node of the tree to check.
 * @min_val: The value of the smallest node visited thus far.
 * @max_val: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_helper(const binary_tree_t *t, int min_val, int max_val)
{
	size_t left_height, right_height, height_diff;

	if (t != NULL)
	{
		if (t->n < min_val || t->n > max_val)
			return (0);
		left_height = calculate_height(t->left);
		right_height = calculate_height(t->right);
		height_diff = left_height > right_height ? left_height - right_height : right_height - left_height;
		if (height_diff > 1)
			return (0);
		return (avl_helper(t->left, min_val, t->n - 1) &&
			avl_helper(t->right, t->n + 1, max_val));
	}
	return (1);
}

/**
 * calculate_height - Measures the height of a binary tree.
 * @t: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t calculate_height(const binary_tree_t *t)
{
	if (t)
	{
		size_t left = 0, right = 0;

		left = t->left ? 1 + calculate_height(t->left) : 1;
		right = t->right ? 1 + calculate_height(t->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
