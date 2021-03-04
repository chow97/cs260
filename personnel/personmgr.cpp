#include "personmgr.h"
using namespace std;

void personmgr::addPerson(const person& aData) 
{
    h.insert(aData);
}

person * personmgr::findPerson(char* id) 
{
    person * aData = NULL;
    h.retrieve(id, aData);
    return aData;   
}

void personmgr::printHtStats()
{
    cout << "Table uses " << h.getSize() << " out of 9973 entries." << endl;
}