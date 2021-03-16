#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "plantermgr.h"

using namespace std;

enum ProcessState {NONE,PLANTING,HARVESTING,PRUNING};

// Plant a plant
void plant(plantermgr& planterMgr,char* line)
{
    int num = 0;
    char* name = nullptr;
    const char* delim = " ";

    char* ptr = strtok(line,delim);
    if (ptr != nullptr)
    {
	num = atoi(ptr);
    }
    name = strtok(nullptr,delim);
    planterMgr.plant(num,name);
}

// Harvest a plant
void harvest(plantermgr& planterMgr,char* line)
{
    char* name = nullptr;
    int start = 0;
    int stop = 0;

    // format: name start stop

    const char* delim = " ";
    char* ptr = strtok(line,delim);
    name = ptr;
    
    ptr = strtok(nullptr,delim);
    if (ptr != nullptr)
    {
	start = atoi(ptr);
    }

    ptr = strtok(nullptr,delim);
    if (ptr != nullptr)
    {
	stop = atoi(ptr);
    }

    planterMgr.harvest(name,start,stop);
}

// Prune a plant
void prune(plantermgr& planterMgr,char* line)
{
    int num = 0;

    // format: num
    num = atoi(line);
    planterMgr.prune(num);
}

int main(int argc,char** argv)
{
    if (argc != 2) 
    {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	exit(0);
    }

    plantermgr planterMgr;
    ProcessState state = NONE;

    char* datafile = argv[1];
    ifstream infile(datafile);

    if (infile.is_open())
    {

	while (!infile.eof())
	{
	    bool skip = false;
	    char line[100];

	    infile.getline(line,100);

	    if (strcmp(line,"start_planting")==0)
	    {
		state = PLANTING;
		skip = true;
	    } else if (strcmp(line,"end_planting")==0)
	    {
		state = NONE;
		skip = true;
	    } else if (strcmp(line,"start_harvest")==0)
	    {
		state = HARVESTING;
		skip = true;
	    } else if (strcmp(line,"end_harvest")==0)
	    {
		state = NONE;
		skip = true;
	    } else if (strcmp(line,"start_pruning")==0)
	    {
		state = PRUNING;
		skip = true;
	    } else if (strcmp(line,"end_pruning")==0)
	    {
		state = NONE;
		skip = true;
	    }

	    if (!skip)
	    {
		skip = false;
		switch (state)
		{
		    case PLANTING:
			plant(planterMgr,line);
			break;
		    case HARVESTING:
			harvest(planterMgr,line);
			break;
		    case PRUNING:
			prune(planterMgr,line);
			break;
		}
	    }
	}
    }
    infile.close();

    return(0);
}
