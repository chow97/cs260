#include "linkedlist.h"

using namespace std;

linkedlist::linkedlist()
{
    head = NULL;
}

linkedlist::~linkedlist()
{
    node * curr = head;
    while(head != NULL)
    {
        curr = curr->next;
        delete head;
        head = curr;
    }   
	head = NULL;
}

void linkedlist::insertFront(const event &data)
{
    node * newNode = new node;
    newNode->item = event(data);
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;
}

void linkedlist::removeBack(event)
{
    if (head->next == NULL) 
    { 
        delete head; 
    } 
    else 
    {
    node *nextToEnd = head;
    node *end = head->next;
    while (end->next != NULL) {
        nextToEnd = end;
        end = end->next;
    }
    delete end;
    nextToEnd->next = NULL;
}
}

bool linkedlist::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}