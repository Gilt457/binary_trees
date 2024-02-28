#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 upon failure
 */
int heap_extract(heap_t **root)
{
	int value, n;
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

	heapify(node);
	n = node->n;
	if (node->parent->right)
	{
		temp = node->parent->right;
		node->parent->right = NULL;
	}
	else
	{
		temp = node->parent->left;
		node->parent->left = NULL;
	}

	free(temp);
	return (n);
}

/**
 * heapify - rebuilds the heap
 * @node: pointer to the root node
 */
void heapify(heap_t *node)
{
	heap_t *idx = node;
	int temp;

	while (idx->left)
	{
		if (idx->right && idx->right->n > idx->left->n)
		{
			temp = idx->n;
			idx->n = idx->right->n;
			idx->right->n = temp;
			idx = idx->right;
		}
		else
		{
			temp = idx->n;
			idx->n = idx->left->n;
			idx->left->n = temp;
			idx = idx->left;
		}
	}
}
