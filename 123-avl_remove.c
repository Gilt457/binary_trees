#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *remove_type(bst_t *node);
int successor(bst_t *node);
void bal(bst_t **node);

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 * Return: Pointer to the new root node of the tree after deletion
 */
avl_t *avl_remove(avl_t *root, int value)
{
	bst_t *node;

	node = bst_remove((bst_t *)root, value);
	bal(&node);

	return ((avl_t *)node);
}

/**
 * bst_remove - Removes a node from a BST
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 * Return: Pointer to the new root node of the tree after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
		root = remove_type(root);

	return (root);
}

/**
 * remove_type - Removes a node based on its number of children
 * @node: Node to remove
 * Return: Pointer to the new root node of the subtree after deletion
 */
bst_t *remove_type(bst_t *node)
{
	bst_t *temp;

	if (node->left == NULL)
	{
		temp = node->right;
		free(node);
		return (temp);
	}
	else if (node->right == NULL)
	{
		temp = node->left;
		free(node);
		return (temp);
	}

	temp = (bst_t *)successor(node->right);
	node->n = temp->n;
	node->right = bst_remove(node->right, temp->n);

	return (node);
}

/**
 * successor - Finds the minimum value in a subtree
 * @node: Pointer to the root node of the subtree
 * Return: Minimum value in the subtree
 */
int successor(bst_t *node)
{
	int min = node->n;

	while (node->left != NULL)
	{
		min = node->left->n;
		node = node->left;
	}

	return (min);
}

/**
 * bal - Checks and restores the balance of a subtree
 * @node: Pointer to the root node of the subtree
 */
void bal(bst_t **node)
{
	int balance;

	if (*node == NULL)
		return;

	balance = binary_tree_balance(*node);

	if (balance > 1)
	{
		if (binary_tree_balance((*node)->left) < 0)
			(*node)->left = binary_tree_rotate_left((*node)->left);
		*node = binary_tree_rotate_right(*node);
	}
	else if (balance < -1)
	{
		if (binary_tree_balance((*node)->right) > 0)
			(*node)->right = binary_tree_rotate_right((*node)->right);
		*node = binary_tree_rotate_left(*node);
	}

	bal(&((*node)->left));
	bal(&((*node)->right));
}
