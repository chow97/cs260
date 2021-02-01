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

void datalogger::containsSector(int sector)
{
	list.constainsSectorNumber(sector);
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
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Histogram data for exposure" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	list.histogramExposure();
	cout << "----------------------------------------------------------------------" << endl;
	cout << "Histogram data for speed" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	list.histogramSpeed();


}

void datalogger::printSectorList(){}
