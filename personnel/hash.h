#ifndef HASH_H
#define HASH_H

#include <cstring>
#include "person.h"
#include <iostream>

using namespace std;


class Hash
{
public:
    Hash();
	Hash(const Hash& aTable);
	~Hash();

	void insert(const person& aData);
	//bool remove(char const * id);
	person * retrieve(char *  id);
	int getSize(void)const;
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
	int size;
	const static int DEFAULT_CAPACITY = 9973;
	

	void destroyTable();
	//int calculateIndex(char * id);
	unsigned long calculateIndex(char *id);
};
#endif