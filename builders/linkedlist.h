#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "structuretype.h"
#include "event.h"

class linkedlist
{
    public:
        linkedlist();
        ~linkedlist();

        void insertFront(const event& data);
        void removeBack();
        bool isEmpty();
        void print();
        int lastSector();
        structure_type lastType();
    
    private:
        struct node
        {
            event item;
            node* next;
        };
        node* head;
};

#endif