#include "list.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

/************************
private:
	data* dArray;
	int capacity;
	int size;
	static const int DEFAULT_CAPACITY = 10;
************************/
list::list() : capacity(DEFAULT_CAPACITY), size(0)
{
    dArray = new data[capacity];
}

list::list(const list& aList)
{
    capacity = aList.capacity;
    dArray = new data[capacity];
    size = aList.size;

    int i;
    for(i=0; i<aList.size; i++)
	dArray[i] = aList.dArray[i]; //this is a deep copy because '=' was overloaded in data class
}

const list& list::operator=(const list& aList)
{
    if (this == &aList)
	return *this;
    else
    {
	//release dynamically allocated memory held by current object
	delete [] dArray; //the destructor of each data object in the array will be invoked

	//make a *this a deep copy of "aList"
	capacity = aList.capacity;
	dArray = new data[capacity];
	size = aList.size;

	int i;
	for(i=0; i<aList.size; i++)
	    dArray[i] = aList.dArray[i]; //this is a deep copy because '=' was overloaded in data class
	return *this;
    }
}

list::~list()
{
    //the destructor of each data object in the array will be invoked before the array will be released
    delete[] dArray; 
}

bool list::insert(const data& aData)
{
    bool ret;
    int i;

    //check if there is still space in the array
    if (size == capacity)
    {
	//create a bigger array and copy data over
	expandArray();
    }

    //we can use '<' to compare because we overloaded '<' in data class
    for(i=0; i<size && dArray[i]<aData; i++)	
	;

    //the data already exists
    if (i<size && dArray[i] == aData)
	ret = false;
    //insert the data here
    else
    {
	//shift array to make space for the data
	int j;
	for(j=size-1; j>=i; j--)
	    dArray[j+1] = dArray[j];
	dArray[i] = aData; 
	size++;
	ret = true;
    }
    return ret;
}

void list::expandArray()
{
    data* temp;
    int i;

    //create a bigger array and copy elements over
    capacity = capacity + 10;
    temp = new data[capacity];
    for(i=0; i<size; i++)
	temp[i] = dArray[i];

    //deallocate the existing array
    delete [] dArray;
    dArray = temp;
}

bool list::remove(const char* key)
{
    bool ret = false;
    int i;
    const char* id;

    //search for the data to be removed
    for(i=0; i<size; i++)
    {
	id = dArray[i].getPccId();
	if (strcmp(key, id) == 0)
	{
	    //remove the data
	    int j;
	    for(j=i; j<size-1; j++)
	    {
		dArray[j] = dArray[j+1];
	    }
	    size--;
	    ret = true;
	}
    }
    //data is not in the list
    return ret;
}

bool list::retrieve(const char* key, data& aData) const
{
    bool ret = false;

    //search for the data to be retrieved
    int i;
    const char* id;
    for(i=0; i<size; i++)
    {
	id = dArray[i].getPccId();
	if (strcmp(key, id) == 0)
	{
	    aData = dArray[i];
	    ret = true;
	}
    }

    //data is not in the list
    return ret;
}

ostream& operator<<(ostream& out, const list& lst)
{
    int i;

    out << "data in the list: " << endl << endl;
    if (lst.size > 0)
	for(i = 0; i < lst.size; i++)
	    //we can use << on data object because we overload << in the data class
	    out << '\t' << lst.dArray[i] << endl;
    else
	out << "no data" << endl;

    return out;
}

int list::getSize(void) const
{
    return size;
}
