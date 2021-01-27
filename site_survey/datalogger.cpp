#include "datalogger.h"

#include <iostream>
#include <iomanip>

using namespace std;

void datalogger::addData(int sector, int exposure, int speed)
{
	list.insert(surveyData(sector, exposure, speed));
}

void datalogger::removeSector(int sector)
{
	list.remove(sector);
}

bool datalogger::containsSector(int sector)
{
	list.retrieve(sector);
}


void datalogger::printReport()
{
	cout << "----------------------------------------------------------------------" << endl;
    cout << "Data Values" << endl;
    cout << "----------------------------------------------------------------------" << endl;
	cout << "Data by Sector" << endl;
	list.printSector();
	cout << "Data by Exposure" << endl;
	list.printExposure();
	cout << "Data by Speed" << endl;
	list.printSpeed();
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Averages per sector" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	list.average();
//	list.printList();
//	cout << "Sector: #" << list.getSectorHead() << " " << list.getExposureHead() << "% exposure, " << list.getSpeedHead() << " km/hr windspeed"<< endl;


}

void datalogger::printSectorList(){}
