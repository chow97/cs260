#ifndef STACK_H
#define STACK_H

#include "event.h"

class stack
{
    public:
        stack();
        ~stack();

        bool push();
        bool pop();
        bool peek();
        bool isEmpty();

    
};

#endif