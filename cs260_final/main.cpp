#include "table.h"

#include <iostream>

using namespace std;

int main()
{
    node * root = NULL;
    build(root);
    display(root);

    /*  PLACE YOUR FUNCTION CALL HERE */
	int sum = sumOfNodes(root);
	cout << "\nSum of Nodes: " << sum << endl;

	node * leaf = NULL;
	copyLeaf(root, leaf);
	display(leaf);
	destroy(leaf);

    display(root);
    destroy(root);
    return 0;
}
