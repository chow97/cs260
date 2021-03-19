//#include "box.h"
#include "bst.h"
#include "plantermgr.h"
#include <iostream>

using namespace std;

int main()
{
	
	plantermgr p;
	bst* b = new bst();

	// insert b
	p.plant(123, "apple");
	p.plant(234, "pear");
	cout << *bst;
	p.prune(123);

	/*
	bst tree;
	tree.insert(box(123, "apple"));
	tree.insert(box(234, "pear"));
	*/
	
}