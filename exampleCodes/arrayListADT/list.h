#ifndef LIST_H
#define LIST_H

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
    data*	dArray;
    int	capacity;
    int	size;

    const static int DEFAULT_CAPACITY = 10;
    void expandArray(void);

};
#endif
