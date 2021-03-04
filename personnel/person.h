#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class person
{
    private:
        char* fname;
        char* lname;
        char* id;
        char* familyid;

    public:
        person();
        person(char* id, char* fname, char* lname, char* familyid);
        person(const person& data);
        ~person();
        char * getFname()const;
        char * getLname()const;
        char * getId()const;
        char * getFamilyid()const;

        void setFname(char* fname);
        void setLname(char* lname);
        void setId(char* id);
        void setFamilyid(char* familyid);
        void print()const;

        friend ostream& operator<<(ostream &os, const person &aPerson);
};
#endif