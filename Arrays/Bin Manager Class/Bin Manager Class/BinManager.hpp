#include <iostream>
#include <string>

#include "InvBin.hpp"

#ifndef BINMANAGER_H
#define BINMANAGER_H


class BinManager
{
public:
	BinManager();
	
	BinManager(int size, string d[], int q[]); // @param: Receives number of bins in use and parallel arrays of item names and quantities.
	string getDescription(int index); // Returns name of one item
	int getQuantity(int index); // Returns quantity of one item
	bool addParts(int bindIndex, int q); // The two bools functions return true if they are successful in their function and false otherwise
	bool removeParts(int binIndex, int q); 
	
	~BinManager();

private:
	InvBin bin[30]; // Array of 30 bins
	int numBins; // Number of bins
};

#endif