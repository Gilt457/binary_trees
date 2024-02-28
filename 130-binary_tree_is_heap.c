#include "binary_trees.h"

/**
 * binary_tree_size - Computes the total number of nodes.
 * @tree: Pointer to the root node of the tree whose size.
 *
 * Return: The total number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size = 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}

/**
 * tree_is_complete - Verifies if a binary tree is complete
 * @tree: Pointer to the root node of the tree to verify
 * @i: Node index
 * @cnodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	int left, right;

	if (!tree)
		return (1);

	if (i >= cnodes)
		return (0);

	left = tree_is_complete(tree->left, 2 * i + 1, cnodes);
	right = tree_is_complete(tree->right, 2 * i + 2, cnodes);

	return (left && right);
}

/**
 * binary_tree_is_complete - Verifies if a binary tree is complete
 * @tree: Pointer to the root node of the tree to verify
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t cnodes;

	if (!tree)
		return (0);

	cnodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, cnodes));
}

/**
 * check_parent - Verifies if all nodes in a binary tree.
 * @tree: Pointer to the root node of the tree to verify
 *
 * Return: 1 if all nodes are less than their parents, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (tree)
	{
		if (tree->n > tree->parent->n)
			return (0);

		left = check_parent(tree->left);
		right = check_parent(tree->right);
	}

	return (left && right);
}

/**
 * binary_tree_is_heap - Verifies if a binary tree is a valid.
 * @tree: Pointer to the root node of the tree to verify
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (binary_tree_is_complete(tree) == 0)
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
