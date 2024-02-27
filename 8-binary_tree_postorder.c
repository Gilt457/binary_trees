#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary tree in post-order fashion
 * @tree: a pointer to the root node of the tree to be traversed
 * @func: a pointer to a function that will be called for each node
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
