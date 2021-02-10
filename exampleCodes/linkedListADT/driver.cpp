#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    list*	students = new list();

    // insert students
    students->insert(data("Red, Panama", "900456222", 3.8));
    students->insert(data("Blue, Stella", "900123456", 4.0));
    students->insert(data("White, Barry", "900233678", 3.9));
    students->insert(data("Gray, Earl", "900333444", 3.6));
    cout << "\noriginal data set -- " << *students;

    students->insert(data("Violet, Ultra", "907654321", 2.6));
    cout << "\nafter insertion -- " << *students;

    // separate block here so that temp will go out of scope
    // and its destructor will be called BEFORE we list memeory leaks
    {
	data	temp;

	students->retrieve("907654321", temp);
	cout << "\nthe newly added student:\n\t" << temp << endl;
    }

    students->remove("907654321");
    cout << "\nafter deletion -- " << *students;

    //test copy constructor
    list *copy = new list(*students);
    cout << "\ncopy of the data set --" << *copy;

    cout << "\nThank you for testing me!" << endl << endl;

    delete copy;
    delete students;

    return 0;
}
