#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - check if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the binary tree
 * @min: minimum value that a node's data can have
 * @max: maximum value that a node's data can have
 *
 * Return: 1 if the tree is a valid BST | 0 otherwise
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
 * get_height - calculate the height of a binary tree
 *
 * @tree: a pointer to the root node of the binary tree
 *
 * Return: the height of the binary tree
 */
int get_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is a valid AVL Tree | 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (1);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right) &&
			is_bst(tree, INT_MIN, INT_MAX));
}
