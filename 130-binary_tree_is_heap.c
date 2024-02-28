#include "binary_trees.h"

int binary_tree_is_heap(const binary_tree_t *tree);
int check_parent(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @i: Index of the current node.
 * @cnodes: Total number of nodes in the tree.
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, 2 * i + 1, cnodes) &&
		tree_is_complete(tree->right, 2 * i + 2, cnodes));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: Tree root.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!binary_tree_is_complete(tree))
		return (0);

	return (check_parent(tree->left) && check_parent(tree->right));
}
