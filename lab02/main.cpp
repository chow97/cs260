#include "dlist.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    printNth(head, 3);

    display(head);
    destroy(head);    
    return 0;
}
