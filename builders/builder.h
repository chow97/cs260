#ifndef BUILDER_H
#define BUILDER_H
#include <iostream>
#include "linkedlist.h"
#include "stack.h"

//using namespace std;

class builder
{
    public:
        int setBuilderNum(int);
        void addRequest(int, structure_type);
        bool doCycle();
        void returnHome();
    private:
        int builderNum;
        int currentSector;
        stack myStack;
        linkedlist list;
        
};
#endif
