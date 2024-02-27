#include "binary_trees.h"

struct queue
{
    const binary_tree_t *node;
    struct queue *next;
};

typedef struct queue queue_t;

queue_t *enqueue(queue_t **rear, const binary_tree_t *node);
void dequeue(queue_t **front);
void level_order(const binary_tree_t *tree, void (*func)(int));

void level_order(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *front = NULL;
    queue_t *rear = NULL;

    if (tree == NULL || func == NULL)
        return;

    rear = enqueue(&rear, tree);
    front = rear;

    while (front != NULL)
    {
        const binary_tree_t *temp = front->node;
        func(temp->n);

        if (temp->left)
            rear = enqueue(&rear, temp->left);

        if (temp->right)
            rear = enqueue(&rear, temp->right);

        dequeue(&front);
    }
}

queue_t *enqueue(queue_t **rear, const binary_tree_t *node)
{
    queue_t *new = malloc(sizeof(*new));
    if (new == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new queue node\n");
        return NULL;
    }

    new->node = node;
    new->next = NULL;

    if (*rear)
        (*rear)->next = new;

    return new;
}

void dequeue(queue_t **front)
{
    queue_t *temp = *front;
    *front = (*front)->next;
    free(temp);
}
