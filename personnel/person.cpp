#include "person.h"
#include <iomanip>
#include <cstring>

person::person():fname(NULL), lname(NULL), id(NULL), familyid(NULL)
{
}

person::person(const char* fname, const char* lname, const char* id, const char* familyid):
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

const char* person::getFname()
{
    return this->fname;
}

const char* person::getLname()
{
    return this->lname;
}

const char* person::getId()
{
    return this->id;
}

const char* person::getFamilyid()
{
    return this->familyid;
}

void person::setFname(const char * fname)
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
void person::setLname(const char * lname)
{
    //release the exisisting memory if there is any
    if(this->lname)
    {
	    delete [] this->lname;
    }

    this->lname = new char[strlen(lname)+1];
    strcpy(this->lname, lname);
}

void person::setId(const char * id)
{
    if(this->id)
    {
	    delete [] this->id;
    }

    //set new name
    this->id = new char[strlen(id)+1];
    strcpy(this->id, id);
}
void person::setFamilyid(const char * familyid)
{
    if(this->familyid)
    {
	    delete [] this->familyid;
    }

    this->familyid = new char[strlen(familyid)+1];
    strcpy(this->familyid, familyid);
}