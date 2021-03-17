#include "table.h"

//Please put the impelementation of the required functions here
int countNodes(node * root)
{
	if(root == NULL)
	{
		return 0;
	}
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
	return countNodes(root->left) + countNodes(root->right) + 1;
}
int sumLeaves(node* root)
{
    int mysum, lsum, rsum = 0;
    if(root == NULL)
	{
        mysum = 0;
		return mysum;
	}

    lsum = sumLeaves(root->left);
    rsum = sumLeaves(root->right);

    mysum = lsum + rsum;
    return mysum;
}
/*
int sumLeaves(node* root)
{
    if(root == NULL)
	{
		return 0;
	}
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    return sumLeaves(root->left) + sumLeaves(root->right);
}
*/