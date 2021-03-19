#include "box.h"

box::box(): num(0), name(NULL)
{
}

box::box(int num, char* name): num(num), name(NULL) 
{
    setNum(num);
    //this->num = num;
    setName(name);
}

box::box(const box& data): name(NULL)
{
    setNum(data.num);
    setName(data.name);   
    
}
const box& box::operator= (const box& src) {
    if(this != &src) {
        this->num = src.num;
        if(this->name) {
            delete [] this->name;
            this->name = nullptr;
        }
        this->name = new char[strlen(src.name) + 1];
        strcpy(name, src.name);
        //cout << &name << " copied: " << name << " len: " << len << endl;
    }
    return *this;
};

box::~box()
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}

int box::getNum()
{
    return num;
}

char* box::getName()
{
    return name;
}

void box::setNum(int num)
{
    this->num = num;
}

void box::setName(char* name)
{
    if(this->name)
    {
	    delete [] this->name;
    }

    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

bool operator<(const box& d1, const box& d2)
{
	return d1.num < d2.num;
}