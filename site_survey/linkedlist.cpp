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
void linkedlist::remove(int sector)
{
    node* curr = sectorHead;
    node* temp = curr;
    if(sectorHead->data.getSector() == sector)
    {
        sectorHead = temp->sectorNext;
        curr =sectorHead;
        delete temp;
    }

    while(temp != NULL && temp->data.getSector() != sector)
    {
        curr = temp;
        temp = temp->sectorNext;
    }
    curr->sectorNext = temp->sectorNext;
    delete temp;
 
}
bool linkedlist::retrieve(int sector)
{
    //search if the data matches
    for(node * curr=sectorHead; curr; curr=curr->sectorNext)
    {
	    if(curr->data.getSector() == sector)
	    {
	        return true;
	    }
    }
    //data is not in the list
    return false;
}

void linkedlist::printSector()
{
    node * curr;

    for(curr = sectorHead; curr; curr = curr->sectorNext)
    {
        cout << "Sector: #" << curr->data.getSector() << " " 
        << curr->data.getExposure() << "% exposure, " 
        << curr->data.getSpeed() << " km/hr windspeed"<< endl;
    }
}

void linkedlist::printExposure()
{

    for(node * curr = exposureHead; curr; curr = curr->exposureNext)
    {
        cout << "Sector: #" << curr->data.getSector() << " " 
        << curr->data.getExposure() << "% exposure, " 
        << curr->data.getSpeed() << " km/hr windspeed"<< endl;
    }
}
void linkedlist::printSpeed()
{
    for(node * curr = speedHead; curr; curr = curr->speedNext)
    {
        cout << "Sector: #" << curr->data.getSector() << " " 
        << curr->data.getExposure() << "% exposure, " 
        << curr->data.getSpeed() << " km/hr windspeed"<< endl;
    }
}

void linkedlist::average()
{
    node* last = sectorHead;
    while (last->sectorNext != NULL)
    {
        last = last->sectorNext;
    }

    for (int i = 1; i <= last->data.getSector(); i++)
    {
        if (retrieve(i))
        {
            printMatch(i);
        }
        else
        {
            cout << "Sector: #" << i << " " << "  -- no data -- " << endl;
        }
    }
    cout << "Sector: #" << last->data.getSector() << " "
    << last->data.getExposure() << "% exposure, "
    << last->data.getSector() << " km/hr windspeed"<< endl;  
}

void linkedlist::printMatch(int sector)
{
    node* curr = sectorHead;
    while (curr->sectorNext != NULL)
    {
        if (curr->data.getSector() == sector && curr->sectorNext->data.getSector() != sector)
        {
            cout << "Sector: #" << sector << " " 
            << getAverageExposure(sector) << "% exposure, " 
            << getAverageSpeed(sector) << " km/hr windspeed"<< endl;
        }
        curr = curr->sectorNext;   
    }
}
int linkedlist::getAverageExposure(int sector)
{
    int sum = 0;
    int count = 0; 
    node* curr = sectorHead;
    while (curr->sectorNext != NULL)
    {
        if (curr->data.getSector() == sector)
        {
            sum = sum + curr->data.getExposure();
            count++;
        }
        curr = curr->sectorNext;
    }
    int avg = sum / count;
    return avg;
}

int linkedlist::getAverageSpeed(int sector)
{
    int sum = 0;
    int count = 0; 
    node* curr = sectorHead;
    while (curr->sectorNext != NULL)
    {
        if (curr->data.getSector() == sector)
        {
            sum = sum + curr->data.getSpeed();
            count++;
        }
        curr = curr->sectorNext;
    }
    int avg = sum / count;
    return avg;
}

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