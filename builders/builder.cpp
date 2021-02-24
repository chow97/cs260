#include "builder.h"


int builder::setBuilderNum(int n)
{
    builderNum = n;
    return builderNum;
}

void builder::addRequest(int sector, structure_type type)
{
    list.insertFront(event(sector, type));
    cout << "Builder #" << builderNum << ":  Received request to build a " 
    << str(type) << " in sector " << sector << endl;
}

bool builder::doCycle()
{
    if(list.isEmpty())
    {
        return false;
    }
    else
    {
        if(currentSector != list.lastSector())
        {
            currentSector = list.lastSector();
            cout << "Builder #" << builderNum << ": Moving to sector " << currentSector << endl;
            cout << "Builder #" << builderNum << ": Building a " << str(list.lastType()) 
            << " in sector " << list.lastSector() << endl;
            myStack.push(event(currentSector, list.lastType()));
            list.removeBack();
            return true;
        }
        if(currentSector == list.lastSector())
        {
            cout << "Builder #" << builderNum << ": Building a " << str(list.lastType()) 
            << " in sector " << list.lastSector() << endl;
            myStack.push(event(currentSector, list.lastType()));
            list.removeBack();
            return true;
        }
    }
}

void builder::returnHome()
{
    while(!myStack.isEmpty())
    {
        if(currentSector != myStack.peekSector())
        {
            currentSector = myStack.peekSector();
            cout << "Builder #" << builderNum << ": Moving to sector " << myStack.peekSector() << endl;
        }
        else
        {
            cout << "Builder #" << builderNum << ": Connected to " << str(myStack.peekType()) 
            << " in sector " << myStack.peekSector() << endl;
            myStack.pop();
        }
    }
    cout << "Builder #" << builderNum << ": Arrived back at base." << endl;
}