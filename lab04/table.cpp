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
    int sum, sumLeft, sumRight;  
    sum = sumRight = sumLeft = 0;  
      
    //Check whether tree is empty  
    if(root == NULL) 
    {  
        return 0;  
    }  
    else 
    {  
        //Calculate the sum of nodes present in left subtree  
        if(root->left != NULL)  
            sumLeft = sumLeaves(root->left);  
          
        //Calculate the sum of nodes present in right subtree  
        if(root->right != NULL)  
              sumRight = sumLeaves(root->right);  
          
        //Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data  
        sum = root->data + sumLeft + sumRight;   
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