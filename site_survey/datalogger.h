#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <iostream>

using namespace std;

class datalogger
{
public:
	datalogger();
	~datalogger();

	void addData(int sector, int exposure, int speed);
	bool containsSector(int sector);
	void removeSector(int sector);
	void listBadSectors;
	

private:
	struct Node
	{
		int sector, exposure, speed;
		Node* next;
	};
	Node* head;

};

#endif
