#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    static int count = 0;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL || n == 1)
    {
        cout << "\nPrinting the last node: " << head->data;
        return;
    } 
/*
    if (++count == n)
    {
        cout << "\nPrinting node number " << n << ": " << head->data;
        return;
    } 
    */

    

    printNth(head->next, n - 1);  
}
int listLength(node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + listLength(head->next);
    }
}
