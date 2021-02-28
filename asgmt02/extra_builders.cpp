#include <iostream>
#include <fstream>
#include <cstring>
#include "structuretype.h"
#include "buildermgr.h"

using namespace std;

#define MAX_COMMAND_LENGTH 50
#define COMMANDS_PER_CYCLE 5

int main(int argc, char** argv) {

    if (argc != 2) {
	cout << "Usage: " << argv[0] << " <datafile>" << endl;
	return(0);
    }

    // Read the data
    char* datafile = argv[1];
    ifstream infile(datafile);

    int builderNum;
    int sectorNum;
    char typeStr[MAX_COMMAND_LENGTH];

    // The first line of the data file contains the number of builders in the format:
    // numbuilders x
    // We can ignore the text "numbuilders" since we only want the x

    char junk[MAX_COMMAND_LENGTH];
    int numBuilders;

    infile >> junk;  // read and discard the text "numbuilders"
    infile >> numBuilders;
    buildermgr bm(numBuilders);

    int cycle = 1;
    bool doneReadingData = false; 
    bool didSomething = false;
    bool done = false;  

    while (!done) {

	cout << "======================================================================" << endl;
	cout << "=== Cycle: " << cycle << endl;
	cout << "======================================================================" << endl;
	cout << endl;
	cycle++;

	// Process a number of incoming commands
	cout << "Dispatching new commands" << endl;
	cout << "------------------------" << endl;
	if (!doneReadingData)
	{
	    for (int i=0;i<COMMANDS_PER_CYCLE;i++)
	    {
		infile >> builderNum;
		infile >> sectorNum;
		infile >> typeStr;
		if (infile.eof())
		{
		    doneReadingData = true;
		}
		else
		{
		    structure_type type = getFromString(typeStr);
		    bm.addRequest(builderNum,sectorNum,type);
		}
	    }
	}
	else
	{
	    cout << "No more commands to read" << endl;
	}
	cout << endl;

	// Ask the builder manager to give each builder a chance to do some work
	cout << "Activating each builder" << endl;
	cout << "-----------------------" << endl;
	didSomething = bm.doWork();

	if (!didSomething)
	{
	    cout << "No builders have any pending commands this cycle" << endl;
	}
	cout << endl;

	// We're done with the loop when there is no more data and none 
	// of the builders did anything during the last cycle.
	done = (doneReadingData && !didSomething);
    }

    // Have each builder return to the base
    cout << "Recalling each builder" << endl;
    cout << "----------------------" << endl;
    bm.allReturnToBase();
    cout << endl;
}
