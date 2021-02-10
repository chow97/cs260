#include <iostream>
#include "table.h"

using namespace::std;

int getmax(node* root)
{
    int max = 0;
    if (root != nullptr) {
	if (root->right == nullptr) {
	    max = root->data;
	} else {
	    max = getmax(root->right);
	}
    }
    return max;
}

void print_with_level(node* root,int level)
{
    if (root != nullptr) {
	for (int i=0;i<level;i++) {
	    cout << "-";
	}

	cout << root->data;

	if ((root->left == nullptr) && (root->right == nullptr)) {
	    cout << "*";
	}
	cout << endl;

	print_with_level(root->left,level+1);
	print_with_level(root->right,level+1);
    }
}

void print_indent(node* root) 
{
    print_with_level(root,0);
}

