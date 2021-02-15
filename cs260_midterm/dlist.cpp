#include "dlist.h"

int countEven(node* head)
{
	if(head == NULL)
	{
		return 0;
	}
	if(head->data % 2 == 0)
	{
		return 1 + countEven(head->next);
	}
	else
	{
		return countEven(head->next);
	}
}

int removeEven(node *& head)
{
	if(head->data & 2 == 0)
	{
		node* temp = head->next;
		temp->previous = NULL;
		delete head;
		removeEven(temp);
	}

}
//put the implmenetation of the required functions here
