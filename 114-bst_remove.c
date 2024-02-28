#include "binary_trees.h"

bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

/**
 * bst_remove - Eliminates a node from a Binary Search Tree.
 *
 * @root: Pointer to the root node of the tree to remove a node.
 * @value: Value to be removed from the tree.
 *
 * Return: Pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* Call the function recursively to remove the node */
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Recursively removes a node from a BST.
 * @root: Pointer to BST root node to remove node.
 * @node: Current BST node.
 * @value: Value to be removed from the BST.
 *
 * Return: Pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		/* If node's value matches target, delete the node */
		if (node->n == value)
			return (bst_delete(root, node));
		/* If node's value is greater than target, search left subtree */
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		/* Else, search right subtree */
		return (bst_remove_recursive(root, node->right, value));
	}
	/* If node is NULL, return NULL */
	return (NULL);
}

/**
 * bst_delete - Removes a binary search tree node.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the node to be deleted from the BST.
 *
 * Return: Pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* Case when no children or only a right child */
	if (node->left == NULL)
	{
		/* Adjust parent's child pointer */
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		/* Adjust right child's parent pointer */
		if (node->right != NULL)
			node->right->parent = parent;
		/* Free the node */
		free(node);
		/* Return the new root */
		return (parent == NULL ? node->right : root);
	}

	/* Case when only a left child */
	if (node->right == NULL)
	{
		/* Adjust parent's child pointer */
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		/* Adjust left child's parent pointer */
		if (node->left != NULL)
			node->left->parent = parent;
		/* Free the node */
		free(node);
		/* Return the new root */
		return (parent == NULL ? node->left : root);
	}

	/* Case when two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	/* Delete the successor */
	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Returns the smallest value of a BST.
 * @root: Pointer to the root node of the BST to search.
 *
 * Return: Smallest value in the tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	/* Traverse left subtree until leftmost node is found */
	while (root->left != NULL)
		root = root->left;
	/* Return leftmost node, which is smallest value in BST */
	return (root);
}
