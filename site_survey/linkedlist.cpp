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
    //search for the data to be retrieved
    node * curr;
    for(curr=sectorHead; curr; curr=curr->sectorNext)
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

void linkedlist::average()
{
    node * last = sectorHead;
    node * curr = sectorHead;
 //   int count;

    while(last->sectorNext != NULL)
    {
        last = last->sectorNext;
    }

    for (int i = 1; i <= last->data.getSector(); i++)
    {
       // count = 1;

        if (i == curr->data.getSector() && curr->data.getSector() != curr->sectorNext->data.getSector())
        {
            cout << "Sector: #" << curr->data.getSector() << " " 
            << curr->data.getExposure() << "% exposure, " 
            << curr->data.getSpeed() << " km/hr windspeed"<< endl;
            curr = curr->sectorNext;
        }
        else if(/*i == curr->data.getSector() && */curr->data.getSector() == curr->sectorNext->data.getSector())
        {
            
            int count = 1;
            int avgExposure = 0;
            
            node* temp = curr;
            curr = curr->sectorNext;
            while (temp->data.getSector() == curr->data.getSector())
            {
                avgExposure = temp->data.getExposure() + curr->data.getExposure();
                temp = curr;
                curr = curr->sectorNext;
                count++;
            }
            
            cout << "Sector: #" << temp->data.getSector() << " " 
            << avgExposure / count << "% exposure, " 
            << curr->data.getSector() << " km/hr windspeed"<< endl;
            
        }
        else
        {
            cout << "Sector: #" << i << " " << "  -- no data -- " << endl;
        }
    }

}
/*
struct node * getAverage(node * curr)
{
    int count = 1;
    int avgExposure = 0;
    node* temp = curr;
    curr = curr->sectorNext;
    while (temp->data.getSector() == curr->data.getSector())
    {
        avgExposure = temp->data.getExposure() + curr->data.getExposure();
        temp = curr;
        curr = curr->sectorNext;
        count++;
    }
    cout << "Sector: #" << temp->data.getSector() << " " 
    << avgExposure / count << "% exposure, " 
    << curr->data.getSector() << " km/hr windspeed"<< endl;

}


void linkedlist::duplicate()
{
    node* temp = sectorHead;
    node* curr = sectorHead->sectorNext;
    int count, avg = 0;
    while(temp->sectorNext != NULL)
    {
        count = 0;
        curr = temp->sectorNext;
        while(curr->sectorNext != NULL)
        {
            if(curr->data.getSector() == temp->data.getSector())
            {
                count++;
                avg = curr->data.getExposure() + temp->data.getExposure();
            }
            curr = curr->sectorNext;
        }
        if(count>1)
        {
            cout << curr->data.getSector() << avg / count << endl;
        }
        temp = temp->sectorNext;
    }
}
  
   */ 


void linkedlist::printMatch()
{

    
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