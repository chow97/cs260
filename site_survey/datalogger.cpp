#include "datalogger.h"

datalogger::datalogger()
{
	head = nullptr;
}

datalogger::~datalogger()
{
	Node* curr = head;
	while(curr)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void datalogger::addData(int sector, int exposure, int speed)
{
	Node * curr = head;
	Node * newNode = new Node();
	newNode
}
