#include "binary_trees.h"

/**
 * binary_tree_enqueue - enqueue a node to the queue
 *
 * @queue: a pointer to the queue
 * @node: a pointer to the node to enqueue
 * @last: last index of the queue
 *
 * Return: void
 */
void binary_tree_enqueue(binary_tree_t **queue, binary_tree_t *node, int *last)
{
	queue[*last] = node;
	(*last)++;
}

/**
 * binary_tree_dequeue - dequeue a node from the queue
 *
 * @queue: a pointer to the queue
 * @front: front index of the queue
 *
 * Return: Return: Dequeued node
 */
binary_tree_t *binary_tree_dequeue(binary_tree_t **queue, int *front)
{
	(*front)++;

	return (queue[*front - 1]);
}

/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1024], *current;
	int front = 0, last = 0;

	if (!tree || !func)
		return;

	binary_tree_enqueue(queue, (binary_tree_t *)tree, &last);

	while (front < last)
	{
		current = binary_tree_dequeue(queue, &front);
		func(current->n);

		if (current->left)
			binary_tree_enqueue(queue, current->left, &last);

		if (current->right)
			binary_tree_enqueue(queue, current->right, &last);
	}
}
