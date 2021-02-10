#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    student s1("joe",15);
    student s2("bob",5);

    student* ps1;

    ps1 = new student("sue",2);
    
    cout << s1 << s2;

    s1.setName("jack");

    cout << s1;
    cout << (*ps1);

    ps1->setTerms(3);
    cout << (*ps1);

    delete ps1;

    return(0);
}
