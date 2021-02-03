#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    static int count = 0;
    if (head == NULL)
    {
        return;
    }

    if (++count == n)
    {
        cout << "Printing node number " << n << ": " << head->data;
    }    
    printNth(head->next, n);
}
