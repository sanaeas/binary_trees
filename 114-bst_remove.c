#include "binary_trees.h"

/**
 * bst_find_min - find the node with the minimum value in a BST
 *
 * @tree: a pointer to the root node of the tree where you will remove a node
 *
 * Return: a pointer to the node with the minimum value
 */
bst_t *bst_find_min(bst_t *tree)
{
	if (!tree)
		return (NULL);

	while (tree->left)
		tree = tree->left;

	return (tree);
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
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right, free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left, free(root);
			return (temp);
		}
		temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
