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
    student s2("bob",5);

    s2.print();
    doSomething(s2);
    s2.print();

    return(0);
}
