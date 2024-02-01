#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 *         0 if the tree is not perfect
 *         0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t nodes = 0;
	size_t pwr = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	pwr = (size_t)_pow_recursion(2, height + 1);
	return (pwr - 1 == nodes);
}

/**
 *pwr_recursion - return the value of x raised to the power of y
 *@i: value to exponentiate
 *@j: the power to raise x 
 *Return: -1 if y is negative
 */

int pwr_recursion(int i, int j)
{
	if (j < 0)
		return (-1);
	if (j == 0)
		return (1);
	else
		return (i * pwr_recursion(i, j - 1));

}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: 0 if tee is NUL
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: 0 if tree is NULL
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lt = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	height_lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lt > height_rt ? height_lt : height_rt);
}
