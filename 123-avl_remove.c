#include "binary_trees.h"

/**
 * binary_tree_successor - find the in-order successor of a node
 *
 * @node: a pointer to the node for which to find the successor
 *
 * Return: a pointer to the in-order successor node
 */
binary_tree_t *binary_tree_successor(binary_tree_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * avl_remove - remove a node from an AVL tree
 *
 * @root: a pointer to the root node of the AVL tree
 * @value: the value to be removed from the AVL tree
 *
 * Return: a pointer to the new root node after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int balance;
	binary_tree_t *temp, *successor;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right, free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left, free(root);
			return (temp);
		}
		successor = binary_tree_successor(root->right), root->n = successor->n;
		root->right = avl_remove(root->right, successor->n);
	}
	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

