#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    cout << "The smallest value is: ";
    printExtreme(root,true);
    cout << endl;

    cout << "The largest value is: ";
    printExtreme(root,false);
    cout << endl;

    node* oddTree = NULL;
    copyOdd(root,&oddTree);
    cout << "The odd tree..." << endl;
    display(oddTree);
    destroy(oddTree);


    display(root);
    destroy(root);
    return 0;
}
