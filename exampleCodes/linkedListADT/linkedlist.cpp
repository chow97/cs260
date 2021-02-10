#include "list.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

/************************
private:
	node * head;
************************/
list::list() : head(NULL), size(0)
{
}

list::list(const list& aList)
{
    if(aList.head == NULL) //or if(!aList.head)
	head = NULL;
    else
    {
	//copy first node
	head = new node;
	assert(head != NULL); //check allocation
	head->item = aList.head->item;

	//copy the rest of the list
	node * destNode = head;				//points to the last node in new list
	node * srcNode = aList.head->next;  //points to node in aList
	while(srcNode != NULL) //or while (srcNode)
	{
	    destNode->next = new node;
	    assert(destNode->next != NULL); //check allocation
	    destNode = destNode->next;
	    destNode->item = srcNode->item;

	    srcNode = srcNode->next;
	}
	destNode->next = NULL;
    }		
}

const list& list::operator= (const list& aList)
{
    if(this == &aList)
	return *this;
    else
    {
	//release dynamically allocated memory held by current object
	node * curr = head;
	while(head)
	{
	    curr = head->next;
	    delete head;
	    head = curr;
	}

	//make *this a deep copy of "aList"
	if(!aList.head)
	    head = NULL;
	else
	{
	    //copy the first node
	    head = new node;
	    assert(head != NULL);
	    head->item = aList.head->item;

	    //copy the rest of the list
	    node * destNode = head;
	    node * srcNode = aList.head->next;

	    while(srcNode)
	    {
		destNode->next = new node;
		assert(destNode->next);
		destNode = destNode->next;
		destNode->item = srcNode->item;

		srcNode = srcNode->next;
	    }
	    destNode->next = NULL;
	}

	return *this;
    }
}

list::~list()
{
    node * curr = head;
    while(head)
    {
	curr = head->next;
	delete head;		//the destructor for individual data (item) is invoked
	head = curr;
    } 
}

bool list::insert (const data& aData)
{
    bool ret;
    node * prev = NULL;
    node * curr = head; 

    //traverse to find the position to insert
    while (curr!=NULL && curr->item < aData)
    {
	prev = curr;
	curr = curr->next;
    }

    //the data already exists
    if(curr && curr->item == aData)
	ret = false;
    //insert the data here
    else
    {
	//create new node to contain the data
	node * newNode = new node;
	newNode->item = aData;
	newNode->next = NULL;

	//link the newNode into the linked list
	newNode->next = curr;
	if(prev == NULL)
	    head = newNode;
	else
	    prev->next = newNode;
	size++;
	ret = true;
    }
    return ret;
}

bool list::remove (const char * key)
{
    bool ret = false;
    const char* id;

    //search for the data to be removed
    node * prev = NULL;
    node * curr = head;
    while (curr)
    {
	id = curr->item.getPccId();
	if(strcmp(key, id) == 0)
	{
	    //remove the data
	    if(!prev)
		head = curr->next;
	    else
		prev->next = curr->next;
	    delete curr;
	    size--;
	    ret = true;
	}

	prev = curr;
	curr = curr->next;
    }
    //data is not in the list
    return ret;
}

bool list::retrieve (const char * key, data & aData)const
{
    bool ret = false;
    //search for the data to be retrieved
    node * curr;
    const char* id;
    for(curr=head; curr; curr=curr->next)
    {
	id = curr->item.getPccId();
	if(strcmp(key, id) == 0)
	{
	    aData = curr->item;
	    ret = true;
	}
    }

    //data is not in the list
    return ret;
}

ostream& operator<<(ostream& out, const list& lst)
{
    list::node*		curr;

    out << "Data in the list: " << endl << endl;
    for(curr = lst.head; curr; curr = curr->next)
	//we can use << on data object because we overload << in the data class
	out << '\t' << curr->item << endl;

    return out;
}


int list::getSize () const
{
    return size;
}









	


