#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	new_node = avl_insert_recursive(tree, *tree, &new_node, value);
	while (*tree)
	{
		balance(*tree);
		tree = &((*tree)->parent);
	}
	return (new_node);
}

/**
 * avl_insert_recursive - Recursive function for inserting a node
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node
 * @new: Double pointer to the new node to be inserted
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the new node after insertion
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int balance_factor;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(parent, value);
		*new = *tree;
		return (*new);
	}
	if (value < (*tree)->n)
		*new = avl_insert_recursive(&((*tree)->left), *tree, new, value);
	else if (value > (*tree)->n)
		*new = avl_insert_recursive(&((*tree)->right), *tree, new, value);
	else
		return (*tree);
	balance_factor = balance(*tree);
	if (balance_factor > 1 && value < (*tree)->left->n)
		return (binary_tree_rotate_right(*tree));
	if (balance_factor < -1 && value > (*tree)->right->n)
		return (binary_tree_rotate_left(*tree));
	if (balance_factor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		return (binary_tree_rotate_right(*tree));
	}
	if (balance_factor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		return (binary_tree_rotate_left(*tree));
	}
	return (*tree);
}

/**
 * balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor, or 0 if tree is NULL
 */
int balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = tree->left ? 1 + height(tree->left) : 0;
	right_height = tree->right ? 1 + height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}
