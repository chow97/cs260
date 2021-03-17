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

void removeLast(node * head)
{
    if (head == NULL)
    {
        return;
    }
    
    if (head->next->next == NULL)
    {
        node* temp = head->next->next;
        delete temp;
        //head->next = NULL;
        
        return;
    }
    else
    {
        removeLast(head->next);
    }
    
}
