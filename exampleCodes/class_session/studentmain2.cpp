#include <iostream>
#include "student.h"

using namespace std;

void doSomething(student other)
{
    // do something with the student
    other.print();
}

int main()
{
    student s1("joe",15);
    student s2("bob",5);

    s1 + s2;

    cout << s1 << s2;

//    cout << s2;
//    doSomething(s2);
//    cout << s2;



    return(0);
}
