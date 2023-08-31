#include "binary_trees.h"

/**
 * array_to_avl_recursive - recursively build an AVL tree from a sorted array
 *
 * @array: a pointer to the sorted array
 * @start: the index of the start of the subarray
 * @end: the index of the end of the subarray
 *
 * Return: a pointer to the root node of the created AVL tree | NULL on failure
 */
avl_t *array_to_avl_recursive(int *array, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	new_node = binary_tree_node(NULL, array[mid]);
	if (new_node == NULL)
		return (NULL);

	new_node->left = array_to_avl_recursive(array, start, mid - 1);
	if (new_node->left)
		new_node->left->parent = new_node;

	new_node->right = array_to_avl_recursive(array, mid + 1, end);
	if (new_node->right)
		new_node->right->parent = new_node;

	return (new_node);
}

/**
 * sorted_array_to_avl - build an AVL tree from a sorted array
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree | NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (array_to_avl_recursive(array, 0, size - 1));
}
