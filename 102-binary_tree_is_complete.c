#include "binary_trees.h"

/**
 * binary_tree_size - calculate the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right)
			+ 1);
}

/**
 * is_complete - helper function to check if a binary tree is complete
 *
 * @tree: a pointer to the current node being checked
 * @index: index of the current node in the complete binary tree
 * @size: size of the tree
 *
 * Return: 1 if tree is complete | 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete | 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (is_complete(tree, 0, size));
}
