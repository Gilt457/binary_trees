#include "binary_tree.h"

void avl_insert(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return;
	}

	avl_insert_recursive(tree, *tree, tree, value);
}

void avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		balance_tree(new, *tree);
		return;
	}

	if (value < (*tree)->n)
		avl_insert_recursive(&(*tree)->left, *tree, new, value);
	else if (value > (*tree)->n)
		avl_insert_recursive(&(*tree)->right, *tree, new, value);
	else
	{
		return;
	}

	(*tree)->height = 1 + MAX(height((*tree)->left), height((*tree)->right));
	(*tree)->bf = balance_factor(*tree);

	balance_tree(new, *tree);
}

void balance_tree(avl_t **tree, avl_t *node)
{
	int bf = balance_factor(node);

	if (bf > 1)
	{
		if (value < node->left->n)
			binary_tree_rotate_right(tree, node);
		else
		{
			binary_tree_rotate_left(&(node->left), node->left->right);
			binary_tree_rotate_right(tree, node);
		}
	}
	else if (bf < -1)
	{
		if (value > node->right->n)
			binary_tree_rotate_left(tree, node);
		else
		{
			binary_tree_rotate_right(&(node->right), node->right->left);
			binary_tree_rotate_left(tree, node);
		}
	}
}

int balance_factor(const avl_t *node)
{
	return height(node->left) - height(node->right);
}

int height(const avl_t *node)
{
	if (node == NULL)
		return 0;
	return node->height;
}
