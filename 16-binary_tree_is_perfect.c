#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Determines if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to examine
 *
 * Return: Returns 0 if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth_node = 0;
	int depth = 0;

	if (!tree)
		return (0);

	depth_node = binary_tree_depth(tree);
	depth = binary_tree_balance(tree);

	if (depth_node == depth)
		return (1);

	return (0);
}

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree
 * @tree: A pointer to the node whose depth is to be measured
 *
 * Return: Returns 0 if the tree is NULL
 */
int binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !(tree->parent))
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: Returns 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (0);

	left = (tree->left) ? (1 + binary_tree_height(tree->left)) : 0;
	right = (tree->right) ? (1 + binary_tree_height(tree->right)) : 0;

	return (left - right);
}

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 *
 * Return: Returns 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);

	left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left > right) ? left : right);
}
