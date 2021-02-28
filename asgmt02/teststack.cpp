#include <iostream>
#include "stack.h"
#include "event.h"
#include "structuretype.h"

using namespace std;

void dumpStack(stack &s)
{
    cout << "Dumping the stack" << endl;
    while (!s.isEmpty())
    {
	const event* result = s.pop();
	cout << "Value: ";
	result->print();
    }
}

int main()
{
    stack* s = new stack(100);
    event e1(1,WIND);
    event e2(2,SOLAR);
    event e3(3,WATER);
    const event* ePtr;

    s->push(e1);
    dumpStack(*s);
    s->push(e2);
    s->push(e3);
    dumpStack(*s);

    delete s;
}
