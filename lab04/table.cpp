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
    int sum, sumL, sumR = 0;  
      
    if(root == NULL) 
    {  
        return 0;  
    }  
    else 
    {  
        if(root->left != NULL)  
            sumL = sumLeaves(root->left);  
          
        if(root->right != NULL)  
              sumR = sumLeaves(root->right);  
          
        sum = root->data + sumL + sumR;   
        return sum;  
    }      
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