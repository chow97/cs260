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
    //empty stack, has nothing to pop
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
/*
//change for linked list as well//  stack::~stack() {delete[] datas;}

void stack::push(int data) {
    //create new node and allocate memory
    struct stack* temp;
    temp = new stack();

    //check if stack (heap) is full. Then inserting an element would lead to stack overflow.
    if (!temp) {
        cout << "\nOverflow";
        exit(1);
    }
    
    //initialize data into temp data field
    temp->data = data;
    
    // put top pointer reference into temp link
    temp->link = top;

    // make temp the top of the stack
    top = temp; 
}


char stack::pop() {
    struct stack* temp;

    //check for stack underflow
    if (top == NULL) {
        cout << "\nStack is empty!" << endl;
        exit(1);
    }
    
    else{
        // assign temp as top
        temp = top;
        
        //assign second node to top
        top = top->link;

        //destroy connection between first and second nodes
        temp->link = NULL;

        //release memory of top node
        free(temp);
    } 
}

int stack::peek() {  ///returns the top element in the stack
    //check for empty stack
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

int stack::isEmpty() {  //checks if the stack is empty or not<F4>
    return top == NULL;
*/