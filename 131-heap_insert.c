#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to be stored in the node that will be inserted
 *
 * Return: A pointer to the newly created node, or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap;
	int size, leaves, subtract, bit, level, temp;

	/* Check if root is NULL */
	if (!root)
		return (NULL);
	/* If root is not NULL, create a new node with the given value */
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	/* Calculate the size of the binary tree */
	size = binary_tree_size(tree);
	leaves = size;
	/* Calculate the level of the binary tree */
	for (level = 0, subtract = 1; leaves >= subtract; subtract *= 2, level++)
		leaves -= subtract;

	/* Traverse the binary tree */
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	/* Create a new node and insert it into the binary tree */
	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	/* Swap the values of the nodes if necessary */
	swap = new_node;
	for (; swap->parent && (swap->n > swap->parent->n); swap = swap->parent)
	{
		temp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = temp;
		new_node = new_node->parent;
	}

	/* Return the newly created node */
	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: The tree to be measured
 *
 * Return: The size of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (!tree)
		return (0);

	/* Recursively calculate the size of the binary tree */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
