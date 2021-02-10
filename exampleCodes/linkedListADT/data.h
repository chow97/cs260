#ifndef DATA_H
#define DATA_H
#include <iostream>


class data
{
public:
    data();
    data(const char* name, const char* pccId, float gpa);
    data(const data& student);		//copy constructor: make current object a copy of "student"
    ~data();				//destructor: release the dynamically allocated memory

    const char* getName() const;
    const char* getPccId() const;
    float getGpa(void) const;

    void setName(const char* name);
    void setPccId(const char* pccId);
    void setGpa(float gpa);

    const data& operator=(const data& student);	 //overloading assignment operator
    friend std::ostream& operator<<(std::ostream& out, const data& student);

private:
    char*	name;
    char*	pccId;
    float	gpa;
};

bool operator< (const data& d1, const data& d2);
bool operator== (const data& d1, const data& d2);

#endif
