#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "linkedlist.h"

class datalogger
{
	private:
		linkedlist list;

	public:
		void addData(int sector,int exposure,int speed);
		void removeSector(int sector);
		void printReport();
		bool containsSector(int sector);
		void printSectorList();

};
#endif
