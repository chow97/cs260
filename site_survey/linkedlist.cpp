#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cassert>

#include <iostream>

linkedlist::linkedlist()
{
    sectorHead = NULL;
    exposureHead = NULL;
    speedHead = NULL;
    size = 0;

}

linkedlist::~linkedlist()
{
    node * curr = sectorHead;
    while(sectorHead)
    {
	curr = sectorHead->sectorNext;
	delete sectorHead;		//the destructor for individual surveyData (item) is invoked
	sectorHead = curr;
    } 
}

void linkedlist::insert (const surveyData& aData)
{
	node * newNode = new node;
    //for sector
	newNode->data = surveyData(aData);
    newNode->sectorNext = NULL;
    
    if(sectorHead == NULL ||sectorHead->data.getSector() >= newNode->data.getSector())
    {
        newNode->sectorNext = sectorHead;
        sectorHead = newNode;
    }
    else
    {
        node* curr = sectorHead;
        while(curr->sectorNext != NULL && curr->sectorNext->data.getSector() <= newNode->data.getSector())
        {
            curr = curr->sectorNext;           
        }
        newNode->sectorNext = curr->sectorNext;
        curr->sectorNext = newNode; 
    }
    //for exposure
	newNode->data = surveyData(aData);
    newNode->exposureNext = NULL;
    
    if(exposureHead == NULL ||exposureHead->data.getExposure() >= newNode->data.getExposure())
    {
        newNode->exposureNext = exposureHead;
        exposureHead = newNode;
    }
    else
    {
        node* curr = exposureHead;
        while(curr->exposureNext != NULL && curr->exposureNext->data.getExposure() <= newNode->data.getExposure())
        {
            curr = curr->exposureNext;           
        }
        newNode->exposureNext = curr->exposureNext;
        curr->exposureNext = newNode; 
    }
    //for speed
	newNode->data = surveyData(aData);
    newNode->speedNext = NULL;
    
    if(speedHead == NULL ||speedHead->data.getSpeed() >= newNode->data.getSpeed())
    {
        newNode->speedNext = speedHead;
        speedHead = newNode;
    }
    else
    {
        node* curr = speedHead;
        while(curr->speedNext != NULL && curr->speedNext->data.getSpeed() <= newNode->data.getSpeed())
        {
            curr = curr->speedNext;           
        }
        newNode->speedNext = curr->speedNext;
        curr->speedNext = newNode; 
    }
}
bool linkedlist::retrieve(surveyData & aData)
{

}
/*
ostream& operator<<(ostream& out, const linkedlist& list)
{
    linkedlist::node*		curr;

    for(curr = list.sectorHead; curr; curr = curr->sectorNext)

    out << "Sector: #" << curr->data.getSector() << " " 
    << curr->data.getExposure() << "% exposure, " 
    << curr->data.getSpeed() << " km/hr windspeed"<< endl;

    return out;
}
*/
void linkedlist::printSector()
{
    node * curr;

    for(curr = sectorHead; curr; curr = curr->sectorNext)

    cout << "Sector: #" << curr->data.getSector() << " " 
    << curr->data.getExposure() << "% exposure, " 
    << curr->data.getSpeed() << " km/hr windspeed"<< endl;
}

void linkedlist::printExposure()
{
    node * curr;

    for(curr = exposureHead; curr; curr = curr->exposureNext)

    cout << "Sector: #" << curr->data.getSector() << " " 
    << curr->data.getExposure() << "% exposure, " 
    << curr->data.getSpeed() << " km/hr windspeed"<< endl;
}
void linkedlist::printSpeed()
{
    node * curr;

    for(curr = speedHead; curr; curr = curr->speedNext)

    cout << "Sector: #" << curr->data.getSector() << " " 
    << curr->data.getExposure() << "% exposure, " 
    << curr->data.getSpeed() << " km/hr windspeed"<< endl;
}

bool linkedlist::remove (int key)
{}

/*
linkedlist::linkedlist()
{
    sectorHead = nullptr;
    exposureHead = nullptr;
    speedHead = nullptr;
}

linkedlist::~linkedlist()
{
    node* curr = sectorHead;
    while(curr)
    {
        sectorHead = curr->sectorNext;
        delete curr;
        curr = sectorHead;
    }
}

void linkedlist::addData(int sector, int exposure, int speed)
{
    node* newNode = new node;
    newNode->sectorData = sector;
    newNode->exposureData = exposure;
    newNode->speedData = speed;

    newNode->sectorNext = nullptr;
    newNode->exposureNext = nullptr;
    newNode->speedNext = nullptr;

    if (sectorHead == nullptr || sectorHead->sectorData >= newNode->sectorData)
    {
        newNode->sectorNext = sectorHead;
        sectorHead = newNode;
        newNode->exposureNext = exposureHead;
        exposureHead = newNode;
        newNode->speedNext = speedHead;
        speedHead = newNode;
    }
    else
    {
        node* curr = sectorHead;
        //for sector
        while(curr->sectorNext != nullptr && curr->sectorNext->sectorData <= newNode->sectorData)
        {
            curr = curr->sectorNext;           
        }
        newNode->sectorNext = curr->sectorNext;
        curr->sectorNext = newNode;      

        //for exposure
         while(curr->exposureNext != nullptr && curr->exposureNext->exposureData <= newNode->exposureData)
         {
             curr = curr->exposureNext;
         }
         newNode->exposureNext = curr->exposureNext;
         curr->exposureNext = newNode;

         //for speed
         while(curr->speedNext != nullptr && curr->speedNext->speedData <= newNode->speedData)
         {
             curr = curr->speedNext;
         }
         newNode->speedNext = curr->speedNext;
         curr->speedNext = newNode;
    }

}

void linkedlist::removeData(int sector)
{
    node* curr = sectorHead;
    node* temp = curr;
    if(sectorHead->sectorData == sector)
    {
        sectorHead = temp->sectorNext;
        curr =sectorHead;
        delete temp;
    }

    while(temp != nullptr && temp->sectorData != sector)
    {
        curr = temp;
        temp = temp->sectorNext;
    }
    curr->sectorNext = temp->sectorNext;
    delete temp;
    */
 /*  
}

int linkedlist::getSectorHead()
{
    int val = 0;
    node* curr = sectorHead;
    while(curr != nullptr)
    {
        val = sectorHead->sectorData;
    }
    return val;
}
int linkedlist::getExposureHead()
{
    node* curr = exposureHead;
    int val = 0;
    while(curr != nullptr)
    {
        val = exposureHead->exposureData;
    }
    return val;
}
int linkedlist::getSpeedHead()
{
    node* curr = speedHead;
    int val = 0;
    while(curr != nullptr)
    {
        val = speedHead->speedData;
    }
    return val;
}

void linkedlist::printList()
{
    node* curr = sectorHead, exposureHead, speedHead;

    while (curr != nullptr)
    {
        cout << curr->sectorData << "\t" << curr->exposureData<< "\t" << curr->speedData << endl;
        curr = curr->sectorNext;
        curr = curr->exposureNext;
        curr = curr->speedNext;
    }
    
}
*/