#include "personmgr.h"
using namespace std;

void personmgr::addPerson(const person& aData) 
{
    char* id = new char[100];
    p.getId();
    h.insert(id, p);
}

person* personmgr::findPerson(const char* id) 
{
    person* p = NULL;
    h.retrieve(id);
    return p;   
}

