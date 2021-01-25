#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class node
{
    public:
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

        void addData(int sector, int exposure, int speed);
        void removeData(int sector);

        void printList();
        int getSectorHead();
        int getExposureHead();
        int getSpeedHead();

};

#endif
