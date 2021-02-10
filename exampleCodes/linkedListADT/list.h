#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <ostream>
#include "data.h"

class list
{
public:
    list();
    list(const list& aList);
    ~list();

    const list& operator=(const list& aList);

    bool insert(const data& aData);
    bool remove(const char* key);
    bool retrieve(const char* key, data& aData) const;
    int getSize(void) const;

    friend std::ostream& operator<<(std::ostream& out, const list& lst);

private:
    struct node
    {
	data item;
	node * next;
    };

    node*	head;
    int		size;
};

#endif
