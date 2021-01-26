#include "surveyData.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

/*************************
private:
	char* sector;
	char* exposure;
	int speed;
*************************/
surveyData::surveyData():sector(NULL), exposure(NULL), speed(0)
{
}
/*
surveyData::surveyData(int sector, int exposure, int speed) :
    sector(NULL),
    exposure(NULL),
    speed(speed)
{
    setSector(sector);
    setExposure(exposure);
}
*/	
surveyData::surveyData(const surveyData& student) : sector(NULL), exposure(NULL)
{
    setSector(student.sector);
    setExposure(student.exposure);
    setSpeed(student.speed);
}

const surveyData& surveyData::operator=(const surveyData& student)
{
    //if it is a self copy, don't do anything
    if(this == &student)
	return *this;
    //make current object *this a copy of the passed in student
    else
    {
	setSector(student.sector);
	setExposure(student.exposure);
	setSpeed(student.speed);
	return *this;
    }
}
/*
surveyData::~surveyData()
{
    if(sector)
	delete[] sector;
    if(exposure)
	delete[] exposure;
}
*/
int surveyData::getSector() const
{
    return(this->sector);
}

int surveyData::getExposure() const
{
    return(this->exposure);
}

int surveyData::getSpeed(void) const
{
    return speed;
}

void surveyData::setSector(int sector)
{
    this->sector = sector;
}

void surveyData::setExposure(int exposure)
{
    this->exposure = exposure;
}

void surveyData::setSpeed(int speed)
{
    this->speed = speed;
}

bool operator<(const surveyData& d1, const surveyData& d2)
{
    int sector1;
    int sector2;

    sector1 = d1.getSector();
    sector2 = d2.getSector();

    if(sector1 < sector2)
	return true;
    else
	return false;
}

bool operator==(const surveyData& d1, const surveyData& d2)
{
    int id1;
    int id2;

    id1 = d1.getExposure();
    id2 = d2.getExposure();

    if(id1 == id2)
	return true;
    else
	return false;
}

ostream& operator<<(ostream& out, const surveyData& student)
{
    out << setw(20) << student.sector
	<< setw(15) << student.exposure
	<< setw(8) << fixed << setprecision(2) << student.speed;
    return out;
}
