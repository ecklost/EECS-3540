/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
* http://turnyournameintoaface.com/
* Author:    Eric C. Klostermeyer <Eric.Klostermeyer@rockets.utoledo.edu>
* Class:     EECS 3540 - Operating Systems and Systems Programming
* Professor: Dr. Gerald Heuring
* Project:   Collatz Sequence
* Due Date:  02 February 2016
*
* User will input the range of values like so (include quotes): <thing here>
* Not complete as of yet.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctime>
#include iostream

using namespace std;

int
main (int argc, char *argv[]) 
{
  // Defaults
  uint32_t nFirst = 1;
  uint32_t nSecond = 10;
 
  // Need two starting values 
  if (argc != 2) 
    {
	  cout << "Specify a range of only two values"; // Input explanation here
	  exit (1);
    }
  
  // Command line values -- see initial block paragraph
  /*CommandLine cmd;
  cmd.AddValue ("nFirst", "Insert a value to start at.", nFirst);
  cmd.AddValue ("nSecond", "Insert a value to end at.", nSecond);
  cmd.parse (argc, argv);*/
  
  cout << argv[0] << endl;
  cout << argv[1] << endl;
  
  // If second value is larger than first, swap values
  if (nSecond < nFirst)
    {
	  uint32_t nTemp = nSecond;
	  nSecond = nFirst;
	  nFirst = nTemp;
    }
  
  // Make arrays 2D -- first is frequency, second is time elapsed)
  uint32_t size = nSecond - nFirst;
  uint32_t **freqArray = new uint32_t*[size];
  for (uint32_t i = 0; i < size; i++) 
    {
      freqArray[i] = new uint32_t[size];
    }
	
  // Collatz
  collatz(freqArray, nFirst, nSecond);
  
  // Output
  ofstream output;
  output.open("freqTable.txt");
  for (uint32_t i = 0; i < size; i++, nFirst++)
    {
	  output << "##" << nFirst << "##" << freqArray[i][0] << "##" << freqArray[i][1] << "##" << endl;
    }		
  output.close();
  
  // Clean up memory and finish
  for (uint32_t i = 0; i < size; i++)
    {
	  delete freqArray[i];
    }
  delete freqArray[];
  return 0;
}

uint32_t**
collatz (uint32_t *freqArray[], uint32_t nFirst, uint32_t nSecond)
{
  uint32_t nTally; 
  uint32_t nCurrent;
  time_t start = time(nullptr);
  
  for (uint32_t i = 0; i < (nSecond - nFirst);)
    { 
	  if (nCurrent == 1) 
	    {
		  // Save to array.
		  time_t end = time(nullptr);
		  freqArray[i][0] = nTally;
		  freqArray[i][1] = end - start;
		  nTally = 0; nCurrent = 0;
		  i++;
		  start = time(nullptr);
	    }
	  else if ((nCurrent % 2) == 0)
	    {
		  nCurrent = nCurrent / 2;
		  nTally++;
	    }
	  else  
	    {
		  nCurrent = nCurrent * 3 + 1;
		  nTally++;
	    }
	}		
  return freqArray;
}
