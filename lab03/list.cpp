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
    node * temp;
    if(head == NULL)
    {
        return;
    }
    if (head->next->next == NULL)
    {
        temp = head->next->next;
        delete temp;
        return;
    }
    else
    {
        head = NULL;
    }
    removeLast(head->next);
    
}



