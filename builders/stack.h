//file: stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "structuretype.h"
#include "event.h"

class stack 
{
    public:
        stack(); 
        ~stack();


        void push(int);
        void pop();

        int peek();
        bool isEmpty(void)const;


    private:	
        struct node
        {
        int data;
        node * next;
        };
        node * top;
};
#endif