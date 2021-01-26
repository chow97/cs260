#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstring>
#include <ostream>
#include "surveyData.h"

using namespace std;

class linkedlist
{
public:
    linkedlist();
//    linkedlist(const linkedlist& aList);
    ~linkedlist();

    const linkedlist& operator=(const linkedlist& aList);

	bool insert(const surveyData& aData);
	bool remove(int key);
	bool retrieve(int key, surveyData& aData) const;
	int getSize(void) const;

	friend std::ostream& operator<<(std::ostream& out, const linkedlist& lst);

private:
	struct node
	{
		surveyData data;
		node * next;
	};

	node*	head;
	int		size;
};

/*
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
*/
#endif
