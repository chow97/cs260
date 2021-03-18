#include "plantermgr.h"

using namespace std;

void plantermgr::plant(int num, char* name)
{
    tree.insert(box(num, name));
    cout << "Planting " << name << " in box " << num << endl;
}

void plantermgr::harvest(char* name, int start, int stop)
{

}

void plantermgr::prune(int num)
{
    tree.remove(num);
}