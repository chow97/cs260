#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    static int count = 0;
    if (head == NULL)
    {
        return;
    }
    cout << "\nPrinting node number " << n << ": ";
    if (head->next == NULL || n == 1)
    {
        cout << head->data;
        return;
    }

    printNth(head->next, n - 1);  
}

