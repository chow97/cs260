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

}

void datalogger::printReport()
{
	cout << "----------------------------------------------------------------------" << endl;
    cout << "Data Values" << endl;
    cout << "----------------------------------------------------------------------" << endl;
	cout << "Data by Sector" << endl;
	cout << list;
//	list.printList();
//	cout << "Sector: #" << list.getSectorHead() << " " << list.getExposureHead() << "% exposure, " << list.getSpeedHead() << " km/hr windspeed"<< endl;


}

void datalogger::printSectorList(){}
