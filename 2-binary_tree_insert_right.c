#include "binary_trees.h"

/**
 * binary_tree_insert_right - Adds a node as the right child of a given node
 * @parent: Pointer to the node where the right child will be added
 * @value: The value to be stored in the new node
 *
 * Return: Address of the newly inserted node,or NULL if operation fails.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
