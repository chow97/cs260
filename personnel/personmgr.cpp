#include "personmgr.h"
using namespace std;

void personmgr::addPerson(const person& aData) 
{
    h.insert(aData);
}

const person * personmgr::findPerson(char* id) 
{
    person * aData = NULL;
    h.retrieve(id, aData);
    return aData;   
}

void personmgr::printHtStats()
{
    cout << "Table uses " << h.getSize() << " out of " << h.getCap() << " entries." << endl;
}

void personmgr::removePerson(char* id)
{
    h.remove(id);
}
void personmgr::print()
{
    cout << "ID: " << p.getId() << endl;
    cout << "First Name: " << p.getFname() << endl;
    cout << "Last Name: " << p.getLname() << endl << endl;
}