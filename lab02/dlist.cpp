#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    static int count = 0;
    if (head == NULL)
    {
        return;
    }
    if (listLength(head) < n)
    {
        cout << "Printing the last node: " << head->data;
    }

    if (++count == n)
    {
        cout << "\nPrinting node number " << n << ": " << head->data;  
    } 
    
    printNth(head->next, n);
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
