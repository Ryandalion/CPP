#include <iostream>

class Stats
{
public:
	Stats();	// Constructor

	double total();	// Calculate total rainfall
	double average();	// Calculate average rainfall
	double lowest(int& lowMonth);	// Calculate lowest rainfall
	double highest(int& highMonth);	// Calculate highest rainfall
	bool storeValue(double userInput);	// Store user input into array

	~Stats();	// Destructor

private:
	double rainData[30]; // 30 element double array
	int index = 0;	// Index for counting number of times data has been stored in array. It should not exceed 30 inputs.
	int i = 0;	// Index for counting months
};