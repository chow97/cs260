//file: stack.cpp
#include "stack.h"
#include <iostream>

stack::stack()
{
    top = NULL;
}

stack::~stack()
{
    node * curr = top;
    while(top)
    {
	curr = top->next;
	delete top;
	top = curr;
    }
    top = NULL;
}

void stack::push(const event& data)
{
    //create new node
    node * newNode = new node;
    newNode->data = event(data);
    newNode->next = NULL;

    //add on top
    newNode->next = top;
    top = newNode;
}
void stack::pop ()
{
    node * temp;
    if(!isEmpty())
    {
	    temp = top;
	    top = top->next;
	    delete temp;
    }
}
bool stack::isEmpty () const
{
    return top==NULL;
}

int stack::peekSector()
{
    if(!isEmpty())
    {
        return top->data.getSector();
    }
}
structure_type stack::peekType()
{
    if(!isEmpty())
    {
        return top->data.getType();
    }
}