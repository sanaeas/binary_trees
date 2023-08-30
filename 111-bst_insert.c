#include "binary_trees.h"

/**
 * bst_insert - insert a value in a Binary Search Tree
 *
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent = NULL;

	if (!tree)
		return (NULL);

	new_node = *tree;

	while (new_node)
	{
		parent = new_node;
		if (value == new_node->n)
			return (NULL);

		if (value < new_node->n)
			new_node = new_node->left;
		else
			new_node = new_node->right;
	}
	new_node = malloc(sizeof(bst_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (!parent)
		*tree = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
