#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "data.h"
class stack 
{
public:
    stack(); 
    stack(const stack& aStack);
    ~stack();

    const stack& operator= (const stack& aStack);

    bool push(const data&);
    bool pop(data&);

    bool peek(data&)const;
    bool isEmpty(void)const;

    friend ostream& operator<<(ostream& out, stack& stk);

private:	
    struct node
    {
	data item;
	node * next;
    };
    node * top;
};
#endif
