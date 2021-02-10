#include "arraystack.h"
#include <fstream>

stack::stack():capacity(DEFAULT_CAPACITY), top(-1)
{
    items = new data[capacity];
}

stack::stack(const stack& aStack)
{
    capacity = aStack.capacity;
    items = new data[capacity];
    top = aStack.top;

    int i;
    for(i=0; i<=aStack.top; i++)
	items[i] = aStack.items[i]; //this is a deep copy because '=' was overloaded in data class
}

const stack& stack::operator=(const stack& aStack)
{
    if(this == &aStack)
	return *this;
    else
    {
	//release dynamically allocated memory held by current object
	delete [] items; //the destructor of each data object in the array will be invoked

	//make a *this a deep copy of "aStack"
	capacity = aStack.capacity;
	items = new data[capacity];
	top = aStack.top;

	int i;
	for(i=0; i<=aStack.top; i++)
	    items[i] = aStack.items[i]; //this is a deep copy because '=' was overloaded in data class
	return *this;
    }
}

stack::~stack()
{
    delete [] items;
}

bool stack::push(const data& aData)
{
    //check if there is still space in the array
    if(top+1 == capacity)
    {
	//create a bigger array and copy data over
	expandArray();
    }
	
    //add on top 
    top++;
    items[top] = aData;
    return true;
}

void stack::expandArray ()
{
    data * temp;
    int i;

    //create a bigger array and copy elements over
    capacity = capacity + 10;
    temp = new data[capacity];
    for(i=0; i<=top; i++)
	temp[i] = items[i];

    //deallocate the existing array
    delete [] items;
    items = temp;
}

bool stack::pop (data& aData)
{
    bool ret = false;
    //empty stack, has nothing to pop
    if(!isEmpty())
    {
	aData = items[top];
	top--;
	ret = true;
    }
    return ret;
}

bool stack::isEmpty () const
{
    return top<0;
}

bool stack::peek (data& aData)const
{
    bool ret = false;
    if(!isEmpty())
    {
	aData = items[top];
	ret = true;
    }
    return ret;
}

ostream& operator<<(ostream& out, stack& stk)
{
    int i;

    out << "Data in the stack: " << endl << endl;
    for(i = stk.top; i >= 0; i--)
	//we can use << on data object because we overload << in the data class
	out << '\t' << stk.items[i] << endl;

    return out;
}
