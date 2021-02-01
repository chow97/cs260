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
    ~linkedlist();

    //const linkedlist& operator=(const linkedlist& aList);

	void insert(const surveyData& aData);
	void remove(int sector);
	bool constainsSectorNumber(int sector);
    void printSector();
    bool isEmpty();
    void printBadSector();
    void printExposure();
    void printSpeed();
    //Average
    void average();
    int getAverageExposure(int sector);
    int getAverageSpeed(int sector);
    void printMatchAvg(int sector);
    //histogram for exposure
    void histogramExposure();
    bool containsExposure(int exposure);
	void countExposure(int exposure);
    //histogram for speed
    void histogramSpeed();
    bool containsSpeed(int speed);
	void countSpeed(int speed);


private:
	struct node
	{
		surveyData data;
        surveyData badSectorData;
		node * sectorNext;
        node * exposureNext;
        node * speedNext;
	};

	node *	sectorHead;
    node *	exposureHead;
    node *	speedHead;
    //node*  getAverage(node * curr); 
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
