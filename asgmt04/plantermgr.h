#ifndef PLANTERMGR_H
#define PLANTERMGR_H
#include "box.h"
#include "bst.h"

class plantermgr
{
    public:
        void plant(int num, char* name);
        void harvest(char* name, int start, int stop);
        void prune(int num);
    private:
        box b;
        bst tree;
};
#endif
//box.h box.cpp bst.h bst.cpp plantermgr.h plantermgr.cpp planters.cpp