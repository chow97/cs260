#include "table.h"

//Please put the impelementation of the required functions here
int sumOfNodes(node * root)
{
	if(root == NULL)
	{
		return 0;
	}
	return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));
}

void copyLeaf(node * src, node *& dest)
{
	if(src == NULL)
	{
		dest = new node;
		dest->data = src->data;
		copyLeaf(src->left, dest->left);
		copyLeaf(src->right, dest->right);
	}
	else
	{
		dest = NULL;
	}
}
