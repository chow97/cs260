#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    int count = countNodes(root);
    cout << "Count nodes: " << count << endl;

    int sum = sumLeaves(root);
    cout << "Sum leaves: " << sum << endl;

    display(root);
    destroy(root);
    return 0;
}
