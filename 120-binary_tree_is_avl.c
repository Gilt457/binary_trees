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
		return (-1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * is_balanced - Checks if a binary tree is balanced
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is balanced, and 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (1);

	balance_factor = height(tree->left) - height(tree->right);

	if (balance_factor > 1 || balance_factor < -1)
		return (0);
	return (is_balanced(tree->left) && is_balanced(tree->right));
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

	if (!binary_tree_is_bst(tree))
		return (0);

	return (is_balanced(tree));
}
