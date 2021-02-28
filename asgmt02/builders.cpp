#include <iostream>
#include <fstream>
#include <cstring>
#include "structuretype.h"
#include "builder.h"

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
    builder* builders;

    infile >> junk;  // read and discard the text "numbuilders"
    infile >> numBuilders;
    builders = new builder[numBuilders];

    for (int i=0;i<numBuilders;i++)
    {
	builders[i].setBuilderNum(i+1);
    }

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
		    builders[builderNum-1].addRequest(sectorNum,type);
		}
	    }
	}
	else
	{
	    cout << "No more commands to read" << endl;
	}
	cout << endl;

	// Each builder gets a cycle to do work if it has any
	didSomething = false;
	cout << "Activating each builder" << endl;
	cout << "-----------------------" << endl;
	for (int i=0;i<numBuilders;i++)
	{
	    if (builders[i].doCycle())
	    {
		didSomething = true;
	    }
	}
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
    for (int i=0;i<numBuilders;i++)
    {
	builders[i].returnHome();
    }
    cout << endl;

    delete [] builders;
}
