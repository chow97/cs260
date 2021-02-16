#ifndef BUILDER_H
#define BUILDER_H

class builder
{
    public:
        int setBuilderNum(int);
        void addRequest(int, structure_type);
        bool doCycle();
        void returnHome();
    private:
        int builderNum;
        int currentSector;
        //stack myStack;
};
#endif
