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

	void insert(char const * const key, const person& aData);
	bool remove(char const * const key);
	person * retrieve(char const *  key);
	int getSize(void)const;
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
	size_t calculateIndex(char const * key);
};
#endif