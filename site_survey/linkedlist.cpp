#include "linkedlist.h"

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
    //node* curr =sectorHead;
    node* newNode = new node;
    newNode->sectorData = sector;
    newNode->exposureData = exposure;
    newNode->speedData = speed;

    newNode->sectorNext =nullptr;
    newNode->exposureNext =nullptr;
    newNode->speedNext =nullptr;

    if (sectorHead == nullptr)
    {
        sectorHead = newNode;
        exposureHead = newNode;
        speedHead = newNode;
    }
	/*
    while(curr->sectorNext != nullptr)
    {
        curr = curr->sectorNext;
    }
    curr->sectorNext = newNode;
    */
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
