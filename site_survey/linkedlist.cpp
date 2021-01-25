#include "linkedlist.h"

#include <iostream>

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
/*
    while(temp != nullptr && temp->sectorData != sector)
    {
        curr = temp;
        temp = temp->sectorNext;
    }
    curr->sectorNext = temp->sectorNext;
    delete temp;
    */
}
/*
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
*/
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