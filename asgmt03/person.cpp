#include "person.h"
#include <iomanip>
#include <cstring>

person::person()
{
    id = NULL;
    fname = NULL;
    lname = NULL;
    familyid = NULL;
}

person::person(char* id,  char* fname,  char* lname,  char* familyid):
    id(NULL),
    fname(NULL),
    lname(NULL),
    familyid(NULL)
{
    setId(id);
    setFname(fname);
    setLname(lname);
    setFamilyid(familyid);
}
	
person::person(const person& data) :id(NULL),  fname(NULL), lname(NULL), familyid(NULL)
{
    setId(data.id);
    setFname(data.fname);
    setLname(data.lname);
    setFamilyid(data.familyid);
}

person::~person()
{
    if(id)
    {
        delete[] id;
        id = NULL;
    }
    if(fname)
    {
        delete[] fname;
        fname = NULL;
    }
	if(lname)
    {
        delete[] lname;
        lname = NULL;
    }
    
    if(familyid)
    {
        delete[] familyid;
        familyid = NULL;
    }
    
}

char * person::getId()const
{
    return id;
}
char * person::getFname()const
{
    return fname;
}

char * person::getLname()const
{
    return lname;
}
char * person::getFamilyid()const
{
    return familyid;
}

void person::setFname(char * fname)
{
    if(this->fname)
    {
	    delete [] this->fname;
    }

    this->fname = new char[strlen(fname)+1];
    strcpy(this->fname, fname);
}
void person::setLname(char * lname)
{
    if(this->lname)
    {
	    delete [] this->lname;
    }

    this->lname = new char[strlen(lname)+1];
    strcpy(this->lname, lname);
}

void person::setId(char * id)
{
    if(this->id)
    {
	    delete [] this->id;
    }

    this->id = new char[strlen(id)+1];
    strcpy(this->id, id);
}
void person::setFamilyid(char * familyid)
{
    if(this->familyid)
    {
	    delete [] this->familyid;
    }

    this->familyid = new char[strlen(familyid)+1];
    strcpy(this->familyid, familyid);
}
/*
ostream& operator<<(ostream &os, const person &aPerson){
    os << "ID: " << aPerson.getId() << "\nFirst Name: " <<
    aPerson.getFname() << "\nLast Name: " <<
    aPerson.getLname() << "\n";

    return os;
}
*/
void person::print()const
{
    cout << "ID: " << getId() << endl;
    cout << "First Name: " << getFname() << endl;
    cout << "Last Name: " << getLname() << endl << endl;
}