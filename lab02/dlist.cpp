#include "dlist.h"

//put the implmenetation of the required functions here
void printNth(node * head,int n)
{
    static int count = 0;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL || n == 1)
    {
        cout << "\nPrinting node number " << n + count << ": " << head->data;
        return;
    }
    count++;
    printNth(head->next, n - 1);  
}

void insertAtN(node *& head,int n,int value)
{
    static int count = 0;
    //insert at beginning
    if (head->previous == NULL && n == 1)
    {
        node* temp = new node();
        temp->data = value;
        temp->previous = NULL;
        temp->next = head;
        head->previous = temp;
        head = temp;
        cout << "\n\nAdded "<< value << " to first node" << ": ";
        return;
    }
    //insert at end
    if (head->next == NULL && n != 1)
    {
        node* temp = new node();
        temp->data = value;
        temp->previous = head;
        temp->next = NULL;
        head->next = temp;
        cout << "\n\nAdded "<< value << " to last node" << ": ";
        return;
    }
    //insert at nth node
    if (n == 1)
    {
        node* temp = new node();
        temp->data = value;
        temp->previous = head->previous;
        temp->next = head;
        temp->previous->next = temp;
        temp->next->previous = temp;
        cout << "\n\nAdded "<< value << " to node number " << n + count << ": "; 
        return;
    }
    count++;
    insertAtN(head->next, n - 1, value);
    
}