#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    int count = 0;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL || n == 1)
    {
        cout << "\nPrinting node number " << n + count << ": " << head->data;
        return;
    }
    count++;
    printNth(head->next, n - 1);  
}

