#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "data.h"
class stack 
{
public:
    stack(); 
    stack(const stack& aStack);
    ~stack();

    const stack& operator=(const stack& aStack);

    bool push(const data&);
    bool pop(data&);

    bool peek(data&) const;
    bool isEmpty(void) const;

    friend ostream& operator<<(ostream& out, stack& stk);

private:
    data* items;
    int capacity;
    int	top;

    static const int DEFAULT_CAPACITY = 100;
    void expandArray();
};

#endif
