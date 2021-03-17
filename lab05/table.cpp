#include "table.h"

//Please put the impelementation of the required functions here
void printExtreme(node* root,bool smallest)
{
    if (root == NULL)
    {
        return;
    }
    if (smallest == true)
    {
        if (root->left != NULL)
        {
            printExtreme(root->left, true);
        }
        cout << root->data;
    }
    if (smallest == false)
    {
        if (root->right != NULL)
        {
            printExtreme(root->right, false);
        }
        cout << root->data;
    }
}
void copyOdd(node* root,node** newRoot)
{
    if(root->data % 2 == 1)
	{
		//copy root
		node *newRoot = new node;
        newRoot->data = root->data;
		copyOdd(root->left, &(newRoot)->left);
		copyOdd(root->right, &(newRoot)->right);
	}
	else
	{
		*newRoot = NULL;
	}
}