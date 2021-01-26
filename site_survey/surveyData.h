#ifndef SURVEYDATA_H
#define SURVEYDATA_H

#include <iostream>

class surveyData
{
public:
	surveyData(int sector, int pccId, int speed);
	~surveyData();						//destructor: release the dynamically allocated memory

	int getSector() const;
	int getExposure() const;
	int getSpeed(void) const;

	void setSector(int sector);
	void setExposure(int exposure);
	void setSpeed(int speed);

//	const surveyData& operator=(const surveyData& student);	 //overloading assignment operator
	friend std::ostream& operator<<(std::ostream& out, const surveyData& student);

private:
	int	sector;
	int	exposure;
	int	speed;
};
/*
bool operator< (const surveyData& d1, const surveyData& d2);
bool operator== (const surveyData& d1, const surveyData& d2);
*/
#endif
