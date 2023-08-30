#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - helper function to check if a binary tree is a valid BST
 *
 * @tree: a pointer to the root node of the tree to check
 * @min: the minimum value for the nodes in the subtree
 * @max: the maximum value for the nodes in the subtree
 *
 * Return: 1 if tree is a valid BST | 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - check if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST | 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
