#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 *
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = 0;
	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
