#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * newHead = NULL;

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Creating the initial list." << endl;
    build(head);
    display(head);

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Reversing the list.";
    reverse(head,newHead);
    display(newHead);
    destroy(newHead);

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Removing the last element.";
    removeLast(head);
    display(head);
    destroy(head);


    return 0;
}
