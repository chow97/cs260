#include <iostream>
#include "list.h"
/*
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
    if (!head->next)
    {
        node * temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    removeLast(head->next);
}
*/
void reverse(node *head, node *&newHead)
{
  if (!head)
  {
    return;
  }

  if (!head->next)
  {
    newHead = head;
    return;
  }

  reverse(head->next, newHead);
  head->next->next = head;
  head->next = NULL;
}

void removeLast(node *&head)
{

  if (!head)
  {
    return;
  }

  if (!head->next)
  {
    node *temp = new node;
    temp = head;
    head = head->next;
    delete temp;
  }
  removeLast(head->next);
}


