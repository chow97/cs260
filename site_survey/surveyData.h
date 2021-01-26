#ifndef SURVEYDATA_H
#define SURVEYDATA_H

#include <iostream>

class surveyData
{
public:
	surveyData();
	surveyData(int sector, int exposure, int speed);
	~surveyData();						//destructor: release the dynamically allocated memory

	int getSector() const;
	int getExposure() const;
	int getSpeed() const;

	void setSector(int sector);
	void setExposure(int exposure);
	void setSpeed(int speed);

private:
	int	sector;
	int	exposure;
	int	speed;
};

#endif
