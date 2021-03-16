#include "table.h"

//Please put the impelementation of the required functions here
int countNodes(node * root)
{
	if(root == nullptr)
	{
		return 0;
	}
    int count = 0;
    if (root->left && root->right)
    {
        count++;
    }
    count += (countNodes(root->left) +  countNodes(root->right)); 
	return count;
}

int sumLeaves(node* root)
{

}