#ifndef SURVEYDATA_H
#define SURVEYDATA_H

#include <iostream>

class surveyData
{
public:
	surveyData();
	surveyData(int sector, int exposure, int speed);
	~surveyData();

	int getSector();
	int getExposure();
	int getSpeed();

	void setSector(int sector);
	void setExposure(int exposure);
	void setSpeed(int speed);

private:
	int	sector;
	int	exposure;
	int	speed;
};

#endif
