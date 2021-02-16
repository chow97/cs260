#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    // Feel free to make any changes here if you want but the end result of your program
    // should have clearly identified output.

    int count = countEven(head);
    cout << "Even count: " << count << endl;

    count = removeEven(head);
    cout << "Removed count: " << count << endl;

    cout << "This list after removing evens:" << endl;

    display(head);
    destroy(head);    
    return 0;
}
