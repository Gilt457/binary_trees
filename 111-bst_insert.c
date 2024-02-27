#include "binary_trees.h"

/**
 * create_new_node - generates a new node
 * @current: pointer to the existing node
 * @value: value to be inserted in the new node
 * Return: pointer to the newly generated node
 */
bst_t *create_new_node(bst_t *current, int value)
{
	bst_t *new_node;

	new_node = binary_tree_node(current, value);
	if (new_node == NULL)
		return (NULL);

	if (value < current->n)
		current->left = new_node;
	else
		current->right = new_node;

	return (new_node);
}

/**
 * bst_insert - adds a value into a Binary Search Tree
 * @tree: double pointer to the root node of the BST where the value.
 * @value: value to be inserted in the new node
 * Return: pointer to the newly added node, or NULL if unsuccessful
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;
	bst_t *current;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	current = *tree;
	while (current != NULL)
	{
		if (current->n == value)
			return (NULL);

		if (value < current->n)
		{
			if (current->left == NULL)
				return (create_new_node(current, value));

			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
				return (create_new_node(current, value));

			current = current->right;
		}
	}
	return (NULL);
}
