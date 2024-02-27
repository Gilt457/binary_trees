#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses a binary tree in pre-order sequence
 * @tree: a pointer to the root node of the tree to be traversed
 * @func: a pointer to a function that is called for each node
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
