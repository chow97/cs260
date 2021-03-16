#include <iostream>
#include "list.h"

void reverse(node * head, node *& newHead)
{
    if (head == NULL)
    {
        return;
    }
    
    if (head->next == NULL)
    {
        newHead = head;
        return;
    }

    reverse(head->next, newHead);
    node * temp = head;
    temp->next = newHead;
    head->next = NULL;
}

void removeLast(node *& head)
{

}



