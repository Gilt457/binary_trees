#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Executes a left-rotation operation.
 * @tree: A pointer to the root node of the tree that will undergo.
 *
 * Return: A pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
