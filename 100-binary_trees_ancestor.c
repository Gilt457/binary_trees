#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the node that is the closest parent.
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the node that is the nearest common ancestor.
 *         or NULL if no common parent was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *f_parent, *s_parent;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f_parent = first->parent;
	s_parent = second->parent;

	if (f_parent == NULL && s_parent == NULL)
		return (NULL);

	if (f_parent == NULL)
		return (binary_trees_ancestor(first, s_parent));

	if (s_parent == NULL)
		return (binary_trees_ancestor(f_parent, second));

	if (f_parent == s_parent)
		return (f_parent);

	return (binary_trees_ancestor(f_parent, s_parent));
}
