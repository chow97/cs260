#include "plantermgr.h"

using namespace std;

void plantermgr::plant(int num, char* name)
{
    tree.insert(box(num, name));
    cout << "Planting " << name << " in box " << num << endl;
}

void plantermgr::harvest(char* name, int start, int stop)
{
    cout << "Harvesting " << name << " from boxes " << start << " to " << stop;
    cout << ". The following boxes will be harvested: ";
    tree.inOrder(start, stop, name);
    cout << endl << endl;
}

void plantermgr::prune(int num)
{
    tree.remove(num);
    cout << "Pruning box number " << num << "." << endl;
}
