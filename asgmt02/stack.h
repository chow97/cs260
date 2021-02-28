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


        void push(const event& data);
        void pop();

        int peekSector();
        structure_type peekType();
        bool isEmpty(void)const;


    private:	
        struct node
        {
        event data;
        node * next;
        };
        node * top;
};
#endif