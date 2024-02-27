#include "binary_trees.h"

/* Function prototypes */
void traverse_binary_tree(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *generate_node(binary_tree_t *node);
void process_and_enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void release_queue(levelorder_queue_t *head);
void dequeue(levelorder_queue_t **head);

/**
 * traverse_binary_tree - Traverses a binary tree in level order.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void traverse_binary_tree(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = generate_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		process_and_enqueue(head->node, head, &tail, func);
		dequeue(&head);
	}
}

/**
 * generate_node - Generates a new node for a level order queue.
 * @node: The binary tree node for the new node to contain.
 * Return: A pointer to the new node, or NULL on failure.
 */
levelorder_queue_t *generate_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * process_and_enqueue - Processes a binary tree node and enqueues.
 * @node: The binary tree node to process.
 * @head: A pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call for each node.
 */
void process_and_enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = generate_node(node->left);
		if (new_node == NULL)
		{
			release_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = generate_node(node->right);
		if (new_node == NULL)
		{
			release_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * release_queue - Releases a level order queue.
 * @head: A pointer to the head of the queue.
 */
void release_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * dequeue - Dequeues the head of a level order queue.
 * @head: A double pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
