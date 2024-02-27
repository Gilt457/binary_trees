#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth_node = 0;
	int depth_tree = 0;

	if (tree == NULL)
		return (0);

	depth_tree = binary_tree_depth(tree);
	return (binary_tree_is_perfect_helper(tree, depth_node, depth_tree));
}

/**
 * binary_tree_is_perfect_helper - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth_node: depth of a node in the tree
 * @depth_tree: depth of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_helper(const binary_tree_t *tree, int depth_node, int depth_tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth_node == depth_tree);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_helper(tree->left, depth_node + 1,
		depth_tree) &&
		binary_tree_is_perfect_helper(tree->right, depth_node + 1,
		depth_tree));
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node in the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
