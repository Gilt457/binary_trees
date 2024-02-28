#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Incorporates a value into a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the Heap to insert the value into.
 * @value: The value to be inserted into the node.
 *
 * Return: A pointer to the inserted node, or NULL if unsuccessful.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap_node;
	int size, leaves, subtract, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, subtract = 1; leaves >= subtract; subtract *= 2, level++)
		leaves -= subtract;
	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swap_node = new_node;
	while (swap_node->parent && (swap_node->n > swap_node->parent->n))
	{
		temp = swap_node->n;
		swap_node->n = swap_node->parent->n;
		swap_node->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Determines the size of a binary tree.
 *
 * @tree: A pointer to the tree to be measured.
 *
 * Return: The size of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
