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
        person(const char* fname, const char* lname, const char* id, const char* familyid);
        person(const person& data);
        ~person();
        const char* getFname();
        const char* getLname();
        const char* getId();
        const char* getFamilyid();

        void setFname(const char* fname);
        void setLname(const char* lname);
        void setId(const char* id);
        void setFamilyid(const char* familyid);

};


#endif