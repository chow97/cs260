#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    cout << "---------------" << endl;
    int max = getmax(root);
    cout << "max: " << max << endl;
    cout << "---------------" << endl;

    print_indent(root);

    display(root);
    destroy(root);

    return 0;
}
