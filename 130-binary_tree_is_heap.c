#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_complete(tree) && check_parent(tree))
		return (1);
	return (0);
}

/**
 * check_parent - checks if all parent nodes are greater than their children
 * @node: a pointer to the node to check
 * Return: 1 if all parents are greater than their children, and 0 otherwise
 */
int check_parent(const binary_tree_t *node)
{
	if (!node)
		return (1);
	if (node->left && node->n < node->left->n)
		return (0);
	if (node->right && node->n < node->right->n)
		return (0);
	return (check_parent(node->left) && check_parent(node->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, and 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * tree_is_complete - checks if a binary tree is complete using level order traversal
 * @tree: a pointer to the root node of the tree to check
 * @index: the index of the current node
 * @nodes: the total number of nodes in the tree
 * Return: 1 if the tree is complete, and 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (tree_is_complete(tree->left, 2 * index + 1, nodes) &&
		tree_is_complete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
