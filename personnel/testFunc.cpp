#include "personmgr.h"
#include "person.h"
#include <iostream>

using namespace std;

int main()
{
    personmgr personMgr;
    /*
    Hash *h = new Hash();
    h->insert(person("G123", "chow", "chow", "F123"));
    h->insert(person("G456", "lee", "kok", "F456"));
    cout << *h;*/
    personMgr.addPerson(person("MC00I238F", "Grady", "Escamilla", "FAM00I3F9O"));
    //personMgr.addPerson(person("G456", "lee", "kok", "F456"));

    personMgr.findPerson("MC00I238F");
    person * p;
    p->print();
    /*
    person  * aData = NULL; 
    if (h->retrieve("G123", aData))
    {
        cout << "find: " << aData << endl;
    }
    else
    {
        cout << "not in list." << endl;
    }
    */
}