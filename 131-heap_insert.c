#include "binary_trees.h"

/**
 * swap - swaps two nodes
 * @a: first node
 * @b: second node
 * Return: nothing
 */
void swap(heap_t **a, heap_t **b)
{
	(*a)->parent = (*b)->parent;
	if ((*b)->parent)
	{
		if ((*b)->parent->left == *b)
			(*b)->parent->left = *a;
		else
			(*b)->parent->right = *a;
	}
	(*b)->parent = *a;
}

/**
 * heapify - fix the heap_max
 * @root: head of the heap tree
 * Return: nothing
 */
void heapify(heap_t **root)
{
	heap_t *tmp = *root, *node = NULL;

	while (1)
	{
		if (tmp->left)
		{
			if (tmp->n < tmp->left->n)
				node = tmp->left;
			if (tmp->right && tmp->n < tmp->right->n && tmp->right->n > node->n)
				node = tmp->right;
		}
		else if (tmp->right)
		{
			if (tmp->n < tmp->right->n)
				node = tmp->right;
		}
		if (node)
		{
			swap(&node, &tmp);
			if (!tmp->parent)
				*root = tmp;
		}
		else
			break;
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *parent;
	char *binary;
	unsigned int idx, size;

	parent = *root;
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if (!(*root))
		return (*root = node);
	for (size = 0; parent; size++)
		parent = parent->parent;
	for (idx = 0, binary = malloc(sizeof(char) * size); idx < size; idx++)
		binary[idx] = !!(size & (1 << idx));
	for (idx = size - 1, parent = *root; idx > 0; idx--)
		parent = binary[idx] ? parent->right : parent->left;
	if (binary[idx])
		parent->right = node;
	else
		parent->left = node;
	node->parent = parent;
	free(binary);
	heapify(root);
	return (node);
}
