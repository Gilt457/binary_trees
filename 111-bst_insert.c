#include "binary_trees.h"

/**
 * create_new_node - creates a new node
 * @current: pointer to the current node
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node
 */
bst_t *create_new_node(bst_t *current, int value)
{
	bst_t *new_node = binary_tree_node(current, value);

	if (value < current->n)
		current->left = new_node;
	else
		current->right = new_node;

	return (new_node);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	bst_t *current = NULL;

	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create the root node */
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	/* Traverse the tree to find the right place to insert the value */
	current = *tree;
	while (current != NULL)
	{
		/* If the value is already present, do nothing */
		if (current->n == value)
			return (NULL);

		/* If the value is smaller, go to the left subtree */
		if (value < current->n)
		{
			/* If the left child is NULL, create the new node there */
			if (current->left == NULL)
				return (create_new_node(current, value));

			/* Otherwise, go to the left child and repeat */
			current = current->left;
		}
		/* If the value is larger, go to the right subtree */
		else if (value > current->n)
		{
			/* If the right child is NULL, create the new node there */
			if (current->right == NULL)
				return (create_new_node(current, value));

			/* Otherwise, go to the right child and repeat */
			current = current->right;
		}
	}
	return (NULL);
}
