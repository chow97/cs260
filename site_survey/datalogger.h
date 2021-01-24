#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "linkedlist.h"

class datalogger
{
	private:
		linkedlist list;

	public:
		void addData(int,int,int);
		void removeSector(int);
		void printReport();
		bool containsSector(int);
		void printSectorList();

};
#endif
