#include "car.hpp"

Car::Car()
{
	year = 0;
	make = "";
	speed = 0;
}

void Car::setYear(int carYear)
{
	year = carYear;
}

void Car::setMake(string carMake)
{
	make = carMake;
}

void Car::setSpeed(int carSpeed)
{
	speed = carSpeed;
}

int Car::accelerate()
{
	speed = speed + 5;
	return speed;
}

int Car::brake()
{
	speed = speed - 5;
	return speed;
}
void Car::displayDetails()
{
	cout << "Model: " << make << endl;
	cout << "Year:  " << year << endl;
	cout << "Final Cruising Speed: " << speed << " mph" << endl;
}
Car::~Car()
{

}