#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 upon failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *node, *temp;

	if (!root || !*root)
		return (0);

	node = *root;
	value = node->n;
	if (!node->left && !node->right)
	{
		free(node);
		*root = NULL;
		return (value);
	}

	temp = max(node);
	node->n = temp->n;
	if (temp->parent->left == temp)
		temp->parent->left = NULL;
	else
		temp->parent->right = NULL;
	free(temp);

	recurse_extract(*root);
	return (value);
}

/**
 * recurse_extract - rebuilds the heap
 * @tree: pointer to the root node
 */
void recurse_extract(heap_t *tree)
{
	heap_t *temp;

	if (!tree || !tree->left)
		return;

	if (!tree->right || tree->left->n > tree->right->n)
		temp = tree->left;
	else
		temp = tree->right;

	if (tree->n < temp->n)
	{
		tree->n = temp->n;
		temp->n = tree->n;
		recurse_extract(temp);
	}
}

/**
 * max - finds the node with the maximum value
 * @tree: pointer to the root node
 * Return: pointer to the node with the maximum value
 */
heap_t *max(heap_t *tree)
{
	heap_t *max_node, *node;

	if (!tree)
		return (NULL);

	node = tree;
	max_node = tree;

	while (node)
	{
		if (node->n > max_node->n)
			max_node = node;

		if (node->left)
		{
			node = node->left;
			if (node->n > max_node->n)
				max_node = node;
		}

		if (node->right)
		{
			node = node->right;
			if (node->n > max_node->n)
				max_node = node;
		}

		node = node->parent;
	}

	return (max_node);
}
