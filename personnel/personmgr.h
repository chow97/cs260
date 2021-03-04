#ifndef PERSONMGR_H
#define PERSONMGR_H
#include <iostream>
#include "hash.h"
#include "person.h"

class personmgr
{
    public:
        void addPerson(const person& aData);
        person * findPerson(char* id);
        void printHtStats();
    private:
        Hash h;
};
#endif