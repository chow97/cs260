#include "hash.h"
#include <iostream>
#include <fstream>

using namespace std; 

Hash::Hash()
{
	size = 0;
	capacity = DEFAULT_CAPACITY;

	table = new node*[DEFAULT_CAPACITY];
	//initialize each head of the individual linked list
	for(int i=0; i<capacity; i++)
	{
		table[i] = NULL;
	}
}

Hash::Hash(const Hash& aTable):capacity(aTable.capacity), size(aTable.size)
{
	table = new node*[capacity];

	//copy the array of linked list
	int i;	
	for(i=0; i<capacity; i++)
	{
		//copy each linked list in the array
		if (aTable.table[i] == NULL)
			table[i] = NULL;
		else
		{
			//copy the first node in current chain
			table[i] = new node(aTable.table[i]->item);

			//copy the rest of the chain
			node * srcNode = aTable.table[i]->next;
			node * destNode = table[i];
			while(srcNode)
			{
				destNode->next = new node(srcNode->item);
				destNode = destNode->next;
				srcNode = srcNode->next;
			}
			destNode->next = NULL;
		}
	}
}


const Hash& Hash::operator= (const Hash& aTable)
{
	if(this == &aTable)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		destroyTable(); 

		//make *this a deep copy of "aTable"
		table = new node*[capacity];
		capacity = aTable.capacity;
		size = aTable.size;

		//copy the array of linked list
		int i;	
		for(i=0; i<capacity; i++)
		{
			//copy each linked list in the array
			if (aTable.table[i] == NULL)
				table[i] = NULL;
			else
			{
				//copy the first node in current chain
				table[i] = new node(aTable.table[i]->item);

				//copy the rest of the chain
				node * srcNode = aTable.table[i]->next;
				node * destNode = table[i];
				while(srcNode)
				{
					destNode->next = new node(srcNode->item);
					destNode = destNode->next;
					srcNode = srcNode->next;
				}
				destNode->next = NULL;
			}
		}		
		return *this;
	}
}


void Hash::destroyTable ()
{
	//delete each chain
	int i;
	for(i=0; i<capacity; i++)
	{
		node * head = table[i];
		node * curr;
		while(head)
		{
			curr = head->next;
			head->next = NULL;
			delete head;
			head = curr;
		}
	}

	//delete the array
	delete [] table;
}
Hash::~Hash()
{
	destroyTable(); 
}

void Hash::insert (const person& aData)
{
	char * id = aData.getId();
	//calculate the insertion position (the index of the array)
	int index = calculateIndex(id);
	//cout << index << endl;

	//create a new node to hold data
	node * newNode = new node(aData);

	//insert the new node at the beginning of the linked list
	if (table[index] = NULL)
	{
		table[index] = newNode;
	}
	else
	{
		newNode->next = table[index];
		table[index] = newNode;
	}
	
}

bool Hash::retrieve (char * key, person *& aData)
{
	//calculate the retrieval position (the index of the array)
	int index = calculateIndex(key);

	//search for the data in the chain (linked list)
	node * curr = table[index];
	
	while (curr)
	{
		char * id = curr->item.getId();
		if(strcmp(key, id) == 0)
		{
			//find match and return the data
			aData = &(curr->item);
			return true;
		}
		else
			curr = curr->next;
	}

	//data is not in the table
	return false;
}

int Hash::calculateIndex (char * id)
{
	// something is very wrong with this hash function -- what?
	int length = strlen(id);
	int hashValue = 0;

	for(int i=0; i<length; i++)
	{
		hashValue += int(id[i]) * int(id[i]);
	}
	//cout << "capacity: " << capacity << endl;
	return hashValue % capacity;
}

ostream& operator<<(ostream& out, Hash& h)
{
	int i;
	Hash::node * curr;

	
	for(i=0; i < h.capacity; i++)
	{
		for(curr = h.table[i]; curr; curr = curr->next)		
			//we can use << on data object because we overload << in the data class
			cout << curr->item << endl;
	}

	return out;
}