#include "datalogger.h"

#include <iostream>
#include <iomanip>

using namespace std;

void datalogger::addData(int sector, int exposure, int speed)
{
	list.addData(sector, exposure, speed);
}

void datalogger::removeSector(int sector)
{
	list.removeData(sector);
}

bool datalogger::containsSector(int sector)
{

}

void datalogger::printReport()
{
	cout << "----------------------------------------------------------------------" << endl;
    cout << "Data Values" << endl;
    cout << "----------------------------------------------------------------------" << endl;
	cout << "Data by Sector" << endl;
	cout << "Sector: #" << list.getSectorHead() << endl;
}

void datalogger::printSectorList(){}
