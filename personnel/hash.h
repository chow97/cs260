#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <cstring>
#include "person.h"
const static int MAX_SIZE = 9973;
using namespace std;


class Hash
{
public:
    Hash();
	Hash(const Hash& aTable);
	~Hash();

	const Hash& operator= (const Hash& aTable);

	void insert(const person& aData);
	//bool remove(char const * id);
	bool retrieve (char * key, person *& aData);
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
	const static int DEFAULT_CAPACITY = 11;

	void destroyTable();
	int calculateIndex(char * id);
	
};
#endif