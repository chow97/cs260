#include "table.h"

//Please put the impelementation of the required functions here
void printExtreme(node* root,bool smallest)
{
    if (smallest == true)
    {
        if (root->left != NULL)
        {
            printExtreme(root->left, true);
            return;
        }
        cout << root->data << " ";
        return;
    }
    if (smallest == false)
    {
        if (root->right != NULL)
        {
            printExtreme(root->right, false);
            return;
        }
        cout << root->data << " ";
        return;
    }
}
void copyOdd(node* root, node** newRoot)
{
    if (root == NULL)
    {
        return;
    }
    if(root->data % 2 != 0)
	{
		//copy root
		*newRoot = new node;
        (*newRoot)->data = root->data;
		return;
	}
	copyOdd(root->left, &(*newRoot)->left);
	copyOdd(root->right, &(*newRoot)->right);
}