#include "binary_trees.h"

/**
 * node_swap - swaps two nodes
 * @node: pointer to the node to be swapped
 */
void node_swap(heap_t **node)
{
	int temp = (*node)->n;
	while ((*node)->parent && (*node)->n > (*node)->parent->n)
	{
		(*node)->n = (*node)->parent->n;
		(*node)->parent->n = temp;
		*node = (*node)->parent;
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
	heap_t *node;
	size_t parent_size, node_size;

	node = binary_tree_node(NULL, value);
	if (!node)
		return (NULL);
	if (!(*root))
	{
		*root = node;
		return (node);
	}
	parent_size = binary_tree_size(*root);
	node_size = 0;
	while (1)
	{
		if (parent_size & node_size)
		{
			if ((*root)->left)
				*root = (*root)->left;
			else
			{
				(*root)->left = node;
				break;
			}
		}
		else
		{
			if ((*root)->right)
				*root = (*root)->right;
			else
			{
				(*root)->right = node;
				break;
			}
		}
		node_size >>= 1;
	}
	node->parent = *root;
	node_swap(&node);
	return (node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of a binary tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
