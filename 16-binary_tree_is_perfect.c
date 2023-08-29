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
	size_t left_height = 0, right_height = 0;

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
 * binary_tree_is_full - check if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full | 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect | 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	return (binary_tree_is_full(tree));
}
