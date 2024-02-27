#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal of a binary tree
 * @tree: A pointer to the root node of the tree to be traversed
 * @func: A pointer to a function that will be called for each node
 *
 * Return: None
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
