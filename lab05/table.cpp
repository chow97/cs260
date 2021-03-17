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

}