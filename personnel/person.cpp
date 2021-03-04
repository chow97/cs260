#include "person.h"
#include <iomanip>
#include <cstring>

person::person():fname(NULL), lname(NULL), id(NULL), familyid(NULL)
{
}

person::person(char* fname,  char* lname,  char* id,  char* familyid):
    fname(NULL),
    lname(NULL),
    id(NULL),
    familyid(NULL)
{
    setFname(fname);
    setLname(lname);
    setId(id);
    setFamilyid(familyid);
}
	
person::person(const person& data) : fname(NULL), lname(NULL), id(NULL), familyid(NULL)
{
    setFname(data.fname);
    setLname(data.lname);
    setId(data.id);
    setFamilyid(data.familyid);
}
person::~person()
{
    if(fname)
    {
        delete[] fname;
    }
	if(lname)
    {
        delete[] lname;
    }
    if(id)
    {
        delete[] id;
    }
    if(familyid)
    {
        delete[] familyid;
    }
    
}

char * person::getFname()const
{
    return fname;
}

char * person::getLname()const
{
    return lname;
}

char * person::getId()const
{
    return id;
}

char * person::getFamilyid()const
{
    return familyid;
}

void person::setFname(char * fname)
{
    //release the exisisting memory if there is any
    if(this->fname)
    {
	    delete [] this->fname;
    }

    //set new name
    this->fname = new char[strlen(fname)+1];
    strcpy(this->fname, fname);
}
void person::setLname(char * lname)
{
    //release the exisisting memory if there is any
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

    //set new name
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

ostream& operator<<(ostream &os, const person &aPerson){
    os << "ID: " << aPerson.getId() << "\nFirst Name: " <<
    aPerson.getFname() << "\nLast Name: " <<
    aPerson.getLname() << "\n";

    return os;
}