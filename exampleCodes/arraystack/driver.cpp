#pragma warning(disable:4305)		// allow conversion of double constants to floats

#include "arraystack.h"

int main()
{
    stack* students = new stack();

    // insert students
    students->push(data("Blue, Stella", "900123456", 4.0));
    students->push(data("Red, Panama", "900456222", 3.8));
    students->push(data("White, Barry", "900233678", 3.9));
    students->push(data("Gray, Earl", "900333444", 3.6));
    cout << "\noriginal data set -- " << *students;

    students->push(data("Violet, Ultra", "907654321", 2.6));
    cout << "\nafter push -- " << *students;

    // separate block here so that temp will go out of scope
    // and its destructor will be called BEFORE we list memeory leaks
    {
	data temp;

	if(! students->peek(temp))
	    cout << "\nstack is empty!" << endl << endl ;
	else
	    cout << "\nthe newly added student: " << temp << endl;

	if(! students->pop (temp))
	    cout << "\nstack is empty!" << endl << endl;
	else
	    cout << "\nafter pop -- " << *students;
    }
	
    //test copy constructor
    stack *copy = new stack(*students);
    cout << "\ncopy of the data set --" << *copy;

    cout << "\nThank you for testing me!" << endl << endl;

    delete copy;
    delete students;

    return 0;
}
