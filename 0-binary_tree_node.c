#include "binary_trees.h"

/**
 * binary_tree_node - Make a node for a binary tree
 * @parent: A pointer to the node's parent
 * @value: The value that the node is to store.
 *
 * Return: A pointer to the new node, or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* Allocate space for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Set the new node's attributes */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
