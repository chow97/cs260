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
    person per1("MC006D018", "Lina", "Major", "FAM00CYXCW");
    person per2("MC00I238F", "Grady", "Escamilla", "FAM00I3F9O");

    personMgr.addPerson(per1);
    personMgr.addPerson(per2);

    //personMgr.addPerson(person("G456", "lee", "kok", "F456"));

    const person* perPtr = personMgr.findPerson("MC006D018");
    perPtr->print();
    const person* perPtr1 = personMgr.findPerson("MC00I238F");
    perPtr1->print();
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