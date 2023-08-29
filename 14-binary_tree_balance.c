#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height from the given node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 1, right_height = 1;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
