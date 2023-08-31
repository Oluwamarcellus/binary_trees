#include "binary_trees.h"

/**
 *bst_insert - inserts a value in a Binary Search Tree
 *@tree: Double pointer to the root node of the BST
 *@value: Value to store in the node
 *Return: Pointer to the newly created node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL, *tmp2 = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = new;
		return (new);
	}

	tmp = *tree;
	while (tmp)
	{
		tmp2 = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	if (tmp2 == NULL)
		tmp2 = new;
	else if (value < tmp2->n)
	{
		tmp2->left = new;
		new->parent = tmp2;
	}
	else
	{
		tmp2->right = new;
		new->parent = tmp2;
	}

	return (new);
}
