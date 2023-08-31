#include "binary_trees.h"

/**
 * bst_find_min - find the in-order successor of a node in a BST
 *
 * @node: node for which to find the in-order successor
 *
 * Return: a pointer to the in-order successor node
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * bst_delete - delete a node from a Binary Search Tree
 *
 * @root: the root node of the tree
 * @node: the node to be deleted
 *
 * Return: a pointer to the new root node after deletion
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor;

	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (!parent ? node->left : root);
	}

	successor = bst_find_min(node->right);
	node->n = successor->n;
	return (bst_delete(root, successor));
}

/**
 * _remove - recursive helper function to remove a node from a BST
 *
 * @root: the root node of the tree
 * @node: the current node being processed
 * @value: the value to be removed
 *
 * Return: a pointer to the new root node after removal
 */
bst_t *_remove(bst_t *root, bst_t *node, int value)
{
	if (!node)
		return (NULL);

	if (value > node->n)
		return (_remove(root, node->right, value));
	if (value < node->n)
		return (_remove(root, node->left, value));
	else
		return (bst_delete(root, node));
}

/**
 * bst_remove - remove a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (_remove(root, root, value));
}
