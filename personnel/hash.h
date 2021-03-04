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

	void insert(char const * const key, const person& aData);
	bool remove(char const * const key);
	person * retrieve(char const *  key);
	int getSize(void)const;
	friend ostream& operator<<(ostream& out, Hash& h);
private:
	struct node
	{
		person item;
		node * next;
	};
	node ** table;
	int capacity;
	int size;
	const static int DEFAULT_CAPACITY = 9973;

	void destroyTable();
	size_t calculateIndex(char const * key);
};
#endif