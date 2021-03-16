#ifndef PERSONMGR_H
#define PERSONMGR_H
#include <iostream>
#include "hash.h"
#include "person.h"

class personmgr
{
    public:
        void addPerson(const person& aData);
        const person * findPerson(char* id);
        void printHtStats();
        void removePerson(char* id);
        void print();
    private:
        Hash h;
        person p;
};
#endif