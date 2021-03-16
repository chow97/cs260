#include "table.h"

//Please put the impelementation of the required functions here
int countNodes(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	return (root->data + countNodes(root->left) + countNodes(root->right));
}

int sumLeaves(node* root)
{
    
}