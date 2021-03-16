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
        if (root->left == NULL)
        {
            cout << root->data;
        }
        printExtreme(root->left, true);
        cout << root->data;
    }
    
    
}
void copyOdd(node* root,node** newRoot)
{

}