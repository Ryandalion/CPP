#include <iostream>
#include <string>

#ifndef CAR_H
#define CAR_H

using std::cout;
using std::endl;
using std::string;

class Car
{
public:
	Car();		// Constructor
	~Car();		// Destructor

	void setYear(int carYear);	// Set year of vehicle
	void setMake(string carMake);	// Set make of vehicle
	void setSpeed(int carSpeed); // Set speed of vehicle
	int accelerate();			// Accelerate car by 5 mph
	int brake();				// Deaccelerate car by 5 mph
	
	void displayDetails();		// Display model, year, speed

private:
	int year;
	string make;
	int speed;
};

#endif