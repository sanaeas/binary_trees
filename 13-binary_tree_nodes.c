#include "binary_trees.h"

/**
 * binary_tree_nodes - count  the nodes with at least 1 child
 *
 * @tree: a pointer to the root of the tree to count the number of nodes
 *
 * Return: the number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (!tree || (tree && !tree->left && !tree->right))
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (left_nodes + right_nodes + 1);
}
