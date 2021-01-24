#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class node
{
    int sectorData;
    node* sectorNext;
    int exposureData;
    node* exposureNext;
    int speedData;
    node* speedNext;
};

class linkedlist
{
    private:
        node* sectorHead;
        node* exposureHead;
        node* speedHead;
    public:
        linkedlist();
        ~linkedlist();

        void addData(int, int, int);
        void removeData(int);

};

#endif