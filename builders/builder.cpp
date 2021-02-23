#include "builder.h"


int builder::setBuilderNum(int n)
{
    builderNum = n;
    return builderNum;
}

void builder::addRequest(int sector, structure_type type)
{
    list.insertFront(event(sector, type));
    std::cout << "Builder #" << builderNum << ":  Received request to build a " 
    << str(list.lastType()) << " in sector " << sector << std::endl;
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
            std::cout << "\nBuilder #" << builderNum << ": Moving to sector " << currentSector << std::endl;
        }
        else
        {
            std::cout << "\nBuilder #" << builderNum << ": Building a " << str(list.lastType()) 
            << " in sector " << currentSector << std::endl;
            list.removeBack();
            myStack.push(currentSector);
            return true;
        }
    }
}

void builder::returnHome()
{
    while(!myStack.isEmpty())
    {
        if(currentSector != myStack.peek())
        {
            currentSector = myStack.peek();
            cout << "\nBuilder #" << builderNum << ": Moving to sector " << currentSector << endl;
            cout << "\nBuilder #" << builderNum << " Connected to " << str(list.lastType()) 
            << " in sector " << currentSector << endl;
            myStack.pop();
        }
        else
        {
            cout << "\nBuilder #" << builderNum << " Connected to " << str(list.lastType()) 
            << " in sector " << currentSector << endl;
            myStack.pop();
        }
    }
}