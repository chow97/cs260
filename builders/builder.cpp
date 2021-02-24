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
            << " in sector " << currentSector << endl;
            list.removeBack();
            return true;
        }
        else
        {
            cout << "Builder #" << builderNum << ": Building a " << str(list.lastType()) 
            << " in sector " << currentSector << endl;
            list.removeBack();
            myStack.push(currentSector);
            return true;
        }
    }
}

void builder::returnHome()
{
    /*
    while(!myStack.isEmpty())
    {
        if(currentSector != myStack.peek())
        {
            currentSector = myStack.peek();
            cout << "Builder #" << builderNum << ": Moving to sector " << currentSector << endl;
        }
        else
        {
            cout << "Builder #" << builderNum << " Connected to " << str(list.lastType()) 
            << " in sector " << currentSector << endl;
            myStack.pop();
        }
    }
    */
}