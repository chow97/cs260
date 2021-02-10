#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

student::student()
{
    name = nullptr;
    terms = 0;
}

student::student(const char* n,int t)
{
    int len = strlen(n) + 1;
    name = new char[len];
    strncpy(name,n,len);

    terms = t;
}

student::student(const student& other)
{
    int len = strlen(other.name) + 1;
    name = new char[len];
    strncpy(name,other.name,len);

    terms = other.terms;
}

const student& list::operator= (const student& other)
{
    if(this == &other)
	return *this;
    else
    {
	terms = other.terms;
	if (name != nullptr)
	    delete [] name;
	int len = strlen(other.name) + 1;
	name = new char[len];
	strncpy(name,other.name,len);
	return *this;
    }
}

student::~student()
{
    cout << "Destructing..." << endl;
    if (name != nullptr)
	delete [] name;
}

void student::print()
{
    cout << name << ": " << terms << endl;
}

student student::operator+(student& other)
{
    cout << "do some adding of students...." << endl;
    terms = terms + other.terms;
    return(*this);
}

ostream& operator<<(ostream& out,student& s)
{
    out << s.name << ": " << s.terms << endl;
    return(out);
}

const char* student::getName()
{
    return(name);
}

int student::getTerms()
{
    return(terms);
}

void student::setName(const char* newname)
{
    if (name != nullptr)
	delete [] name;

    int len = strlen(newname) + 1;
    name = new char[len];
    strncpy(name,newname,len);
}

void student::setTerms(int newterms)
{
    terms = newterms;
}


