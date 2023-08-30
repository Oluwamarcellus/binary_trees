#include "binary_trees.h"

/**
 *binary_tree_balance - measures the balance factor of a binary tree
 *@tree: Pointer to the tree to measure
 *Return: Balance factor of the tree
 *
 *
 *Balance Factor = Height of Left Subtree - Height of Right Subtree
 */
int tree_height(binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	if (tree->left)
		left = tree_height(tree->left);
	else
		left = -1;
	if (tree->right)
		right = tree_height(tree->right);
	else
		right = -1;

	return (left - right);
}

/**
 *tree_height - Gets the height of a tree
 *@tree: Pointer to the root node of the tree
 *Return: The height of the tree
 */

int tree_height(binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = 1 + tree_height(tree->left);
	if (tree->right)
		right = 1 + tree_height(tree->right);

	return (left > right ? left : right);
}
