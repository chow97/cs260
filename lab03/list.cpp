#include <iostream>
#include "list.h"

void reverse(node * head, node *& newHead)
{
    if (head == NULL)
    {
        return;
    }
    node* first = head;
    node* temp = first->next;
    if (temp == NULL)
    {
        newHead = first;
        return;
    }

    reverse(temp, newHead);
    temp->next = first;
    first->next = NULL;
}

void removeLast(node *& head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head->next;
    }
    if (head->next->next == NULL)
    {        
        head->next = NULL;        
        return;
    }
    removeLast(head->next);
}
