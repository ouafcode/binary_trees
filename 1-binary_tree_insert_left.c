#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * @parent: pointer to the node to insert the left-child.
 * @value: value to store in the new node.
 *
 * Return: a pointer to new node
 *         OR Null on failure
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new;/*new node*/
if (parent == NULL)
return (NULL);
new = malloc(sizeof(binary_tree_t));
if (new == NULL)
return (NULL);
new->n = value;
new->parent = parent;
new->left = parent->left;
new->right = NULL;
parent->left = new;
if (new->left)
new->left->parent = new;

return (new);
}
