#include "binary_trees.h"

/**
 * binary_tree_delete - Erases a complete binary tree
 * @tree: Pointer to the root node of the tree to erase
 *
 * Return: None
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Erase both subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Afterwards, erase the node */
	free(tree);
}
