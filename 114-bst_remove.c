#include "binary_trees.h"

bst_t *remove_node(bst_t *root, int value);
bst_t *recursive_remove(bst_t *root, bst_t *node, int value);
bst_t *delete_node(bst_t *root, bst_t *node);
bst_t *successor_inorder(bst_t *root);

/**
 * remove_node - Removes a node from a Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing.
 */
bst_t *remove_node(bst_t *root, int value)
{
	return (recursive_remove(root, root, value));
}

/**
 * recursive_remove - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *recursive_remove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_node(root, node));
		if (node->n > value)
			return (recursive_remove(root, node->left, value));
		return (recursive_remove(root, node->right, value));
	}
	return (NULL);
}

/**
 * delete_node - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent_node = node->parent, *successor_node = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent_node != NULL && parent_node->left == node)
			parent_node->left = node->right;
		else if (parent_node != NULL)
			parent_node->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent_node;
		free(node);
		return (parent_node == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent_node != NULL && parent_node->left == node)
			parent_node->left = node->left;
		else if (parent_node != NULL)
			parent_node->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent_node;
		free(node);
		return (parent_node == NULL ? node->left : root);
	}

	/* Two children */
	successor_node = successor_inorder(node->right);
	node->n = successor_node->n;

	return (delete_node(root, successor_node));
}

/**
 * successor_inorder - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *successor_inorder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
