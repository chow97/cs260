#include "hash.h"

Hash::Hash() :
	size(0),
	capacity(DEFAULT_CAPACITY),
	table(new node*[DEFAULT_CAPACITY])
{
	//initialize each head of the individual linked list
	for(int i=0; i<capacity; i++)
	{
		table[i] = NULL;
	}
}
/*
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
*/

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
void Hash::insert (char const * const key, const person& aData)
{
	//calculate the insertion position (the index of the array)
	size_t index = calculateIndex(key);

	//create a new node to hold data
	node * newNode = new node;
	newNode->item = person(aData);

	//insert the new node at the beginning of the linked list
	newNode->next = table[index];
	table[index] = newNode;
}

person * Hash::retrieve(char const *  key)
{
	//calculate the retrieval position (the index of the array)
	size_t index = calculateIndex(key);

	//search for the data in the chain (linked list)
	node * curr = table[index];
	char id[100];
	while (curr)
	{
		curr->item.getId();
		if(strcmp(key, id) == 0)
		{
			//find match and return the data
			return &curr->item;
		}
		else
			curr = curr->next;
	}
}

size_t Hash::calculateIndex (char const *  key)
{
	// something is very wrong with this hash function -- what?
	size_t length = strlen(key);
	size_t hashValue = 0;

	for(size_t i=0; i<length; i++)
	{
		hashValue += size_t(key[i]) * size_t(key[i]);
	}
	return hashValue % capacity;
}

ostream& operator<<(ostream& out, Hash& h)
{
	int i;
	Hash::node * curr;

	cout << "Data in the table: " << endl << endl;
	for(i=0; i < h.capacity; i++)
	{
		for(curr = h.table[i]; curr; curr = curr->next)		
			//we can use << on data object because we overload << in the data class
			cout << '\t' << curr->item << endl;
	}

	return out;
}