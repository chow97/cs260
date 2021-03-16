#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <cstring>
#include "person.h"
using namespace std;


class Hash
{
public:
    Hash();
	Hash(const Hash& aTable);
	~Hash();
	
	void insert(const person& aData);
	bool remove(char * key);
	bool retrieve (char * key, person *& aData);
	int tableSize();
	int getCap();

	friend ostream& operator<<(ostream& out, Hash& h);

private:
	struct node
	{
		person item;
		node * next;
		node(const person& aData) : item(aData), next(NULL) {}
	};
	node ** table;
	int capacity;
	const static int DEFAULT_CAPACITY = 9973;

	int calculateIndex(char * id);
	
};
#endif