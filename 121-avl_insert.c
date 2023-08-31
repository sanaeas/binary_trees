#include "binary_trees.h"

/**
 * balance_factor - calculate the balance factor of a binary tree node
 *
 * @tree: a pointer to the root of the tree
 *
 * Return: balance factor
 */
int balance_factor(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * avl_insert_recursive - recursively insert a value into an AVL tree
 *
 * @tree: a double pointer to the root of the tree
 * @parent: a pointer to the parent node
 * @new_node: a double pointer to store the newly created node
 * @value: the value to be inserted
 *
 * Return: a pointer to the root of the tree after insertion and balancing
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int bf;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left,
				*tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
				*tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bf = balance_factor(*tree);
	if (bf > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bf < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bf > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bf < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - insert a value in an AVL tree
 *
 * @tree:a double pointer to the root of the tree
 * @value: the value to be inserted
 *
 * Return: a pointer to the created node | NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}
