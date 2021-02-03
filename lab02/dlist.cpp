#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    int count = 1;
    if (count == n)
    {
        cout << "Printing " << n << "th" << head->data;
    }
    printNth(head->next, n+1);   
}