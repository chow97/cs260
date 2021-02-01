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
    if (!isEmpty())
    {
        node * curr = sectorHead;
        while(curr != NULL)
        {
            node* next = curr->sectorNext;
	        delete curr;		//the destructor for individual surveyData (item) is invoked
	        curr = next;
        }
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
    node* temp = NULL;
    if(sectorHead->data.getSector() == sector)
    {
        sectorHead = curr->sectorNext;
        delete curr;
    }

    while(curr != NULL && curr->data.getSector() != sector)
    {

            temp = curr;
            curr = curr->sectorNext;
    }
    temp->sectorNext = curr->sectorNext;
}

bool linkedlist::constainsSectorNumber(int sector)
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
    node * curr = sectorHead;
    /*if((curr->data.getExposure() < 0) || (curr->data.getSpeed() < 0))
    {
        cout << curr->data.getSector();
        curr = curr->sectorNext;
        while (curr != NULL)
        {
            cout << ", ";
            cout << curr->data.getSector();  
            curr = curr->sectorNext;
        }
        cout << endl;
    }
    else
    {*/
        for(curr = sectorHead; curr; curr = curr->sectorNext)
        {
            cout << "Sector: #" << curr->data.getSector() << " " 
            << curr->data.getExposure() << "% exposure, " 
            << curr->data.getSpeed() << " km/hr windspeed"<< endl;
        }
   // }  
}

void linkedlist::printBadSector()
{
    node* curr = sectorHead;
    cout << curr->data.getSector();
    curr = curr->sectorNext;
    while (curr != NULL)
    {
        cout << ", ";
        cout << curr->data.getSector();  
        curr = curr->sectorNext;
    }
    cout << endl;
    
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
        if (constainsSectorNumber(i))
        {
            printMatchAvg(i);
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

void linkedlist::printMatchAvg(int sector)
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

bool linkedlist::containsExposure(int exposure)
{
    for (node* curr = exposureHead; curr != NULL; curr = curr->exposureNext)
    {
        if (curr->data.getExposure() == exposure)
        {
            return true;
        } 
    }
    return false;    
}
void linkedlist::histogramExposure()
{
    node* last = exposureHead;
    while (last->exposureNext != NULL)
    {
        last = last->exposureNext;
    }
    
    for (int i = 1; i <= last->data.getExposure(); i++)
    {
        if (containsExposure(i))
        {
            countExposure(i);
        }
        else
        {
            cout << i << ", " << 0 << endl;
        }
    }
    
}
void linkedlist::countExposure(int exposure)
{
    int count = 0;
    for (node* curr = exposureHead; curr != NULL; curr = curr->exposureNext)
    {
        if (curr->data.getExposure() == exposure)
        {
            count++;
        }
        
    }
    cout << exposure << ", " << count << endl;
}

bool linkedlist::containsSpeed(int speed)
{
    for (node* curr = speedHead; curr != NULL; curr = curr->speedNext)
    {
        if (curr->data.getSpeed() == speed)
        {
            return true;
        } 
    }
    return false;    
}
void linkedlist::histogramSpeed()
{
    node* last = speedHead;
    while (last->speedNext != NULL)
    {
        last = last->speedNext;
    }
    
    for (int i = 1; i <= last->data.getSpeed(); i++)
    {
        if (containsSpeed(i))
        {
            countSpeed(i);
        }
        else
        {
            cout << i << ", " << 0 << endl;
        }
    }
    
}
void linkedlist::countSpeed(int speed)
{
    int count = 0;
    for (node* curr = speedHead; curr != NULL; curr = curr->speedNext)
    {
        if (curr->data.getSpeed() == speed)
        {
            count++;
        }
        
    }
    cout << speed << ", " << count << endl;
}
bool linkedlist::isEmpty()
{
    if (sectorHead == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
