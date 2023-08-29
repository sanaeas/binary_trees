#include "binary_trees.h"

/**
 * check_perfect - check if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 * @depth: depth of the left leaf
 * @level: current level depth
 *
 * Return: 1 if tree is perfect | 0 otherwise
 */
int check_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree && tree->left == NULL && tree->right == NULL)
		if (depth == level)
			return (1);

	if (tree && (tree->left == NULL || tree->right == NULL))
		return (0);

	return (check_perfect(tree->left, depth, level + 1) &&
			check_perfect(tree->right, depth, level + 1));
}

/**
 * calculate_depth - calculates the depth of a binary tree
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: Depth of the tree
 */
size_t calculate_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (calculate_depth(tree->left) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect | 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = calculate_depth(tree) - 1;

	return (check_perfect(tree, depth, 0));
}

