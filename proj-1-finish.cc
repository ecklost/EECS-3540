/*
 * Author:    Eric C. Klostermeyer <Eric.Klostermeyer@rockets.utoledo.edu>
 * Class:     EECS 3540 - Operating Systems and Systems Programming
 * Professor: Dr. Gerald Heuring
 * Project:   Collatz Sequence
 * Due Date:  February 2, 2016
 *
 * User will input the range of values like so (include quotes): project-1.exe 1 50
 * Beta version 0.97
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <fstream>

using namespace std;

void collatz(uint32_t freqArray[], uint32_t nFirst, uint32_t nSecond)
{
	uint32_t nTally = 0;
	uint32_t nCurrent = nFirst;
	uint32_t nFirstTemp = nFirst;

	for (uint32_t i = 0; i < nSecond;)
	{
		if (nCurrent == 1)
		{
			// Save to array.
			freqArray[i] = nTally;
			nFirst++;
			nTally = 0;
			nCurrent = nFirst;
			i++;
		}
		else if ((nCurrent % 2) == 0 && nCurrent != 0) // even
		{
			nCurrent = nCurrent / 2;
			nTally++;
		}
		else // odd, or 0
		{
			nCurrent = nCurrent * 3 + 1;
			nTally++;
		}
	}
	nFirst = nFirstTemp; // Reset for counter

	// Output
	std::ofstream output;
	output.open("freqTable.txt");
	output << "## No. ## Stopping Time " << endl;
	for (uint32_t i = 0; i < nSecond; i++, nFirst++)
	{
		output << "## " << nFirst << " ## " << freqArray[i] << " ## "  << endl;
	}
	output.close();

	// Clean up memory and finish
	delete[] freqArray;

	return;
}


int main(int argc, char *argv[])
{
	// Defaults
	uint32_t nFirst = 0;
	uint32_t nSecond = 1000;

	// Need two starting values 
	if (argc != 3)
	{
		cout << "Specify a range of only two values" << endl;
		cout << "Example: project-1.exe 0 100" << endl;
		cout << "Press enter to exit." << endl;
		getchar();
		exit(1);
	}

	nFirst = atoi(argv[1]);
	nSecond = atoi(argv[2]);

	// If second value is larger than first, swap values
	if (nSecond < nFirst)
	{
		uint32_t nTemp = nSecond;
		nSecond = nFirst;
		nFirst = nTemp;
	}
	if (nFirst == 0) nSecond++; // Account for zero

	// Array for stopping times.
	uint32_t *freqArray = new uint32_t[nSecond];

	// Collatz
	collatz(freqArray, nFirst, nSecond);
	
	return 0;
}
