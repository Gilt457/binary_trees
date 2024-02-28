#include "binary_trees.h"

/**
 * heap_insert - This function adds a value into a Max Binary Heap
 * @root: This is a double pointer to the root node of the Heap where the value will be inserted
 * @value: This is the value that will be stored in the node that will be inserted
 *
 * Return: This function returns a pointer to the newly created node, or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap;
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

	swap = new_node;
	for (; swap->parent && (swap->n > swap->parent->n); swap = swap->parent)
	{
		temp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - This function calculates the size of a binary tree
 * @tree: This is the tree whose size will be measured
 *
 * Return: This function returns the size of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
