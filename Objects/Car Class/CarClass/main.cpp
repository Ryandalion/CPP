#include <iostream>
#include <string>

#include "car.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string carMake;
	int carYear;
	int carSpeed;
	bool running = false;
	int input;

	Car Vehicle1;

	cout << "Please enter your car's year: " << endl;
	cin >> carYear;
	cin.ignore();
	cout << "Please enter your car's model: " << endl;
	getline(cin, carMake);
	cout << "Please enter your car's current speed: " << endl;
	cin >> carSpeed;

	Vehicle1.setMake(carMake);
	Vehicle1.setYear(carYear);
	Vehicle1.setSpeed(carSpeed);
	
	while (running != true)
	{
		cout << endl;
		cout << "Please choose from the following options: " << endl;
		cout << "1. Accelerate by 5 mph" << endl;
		cout << "2. Deaccelerate by 5 mph" << endl;
		cout << "3. Turn off and exit vehicle" << endl;
		cin >> input;
		if(input == 1)
			{
				cout << "You have chosen to accelerate" << endl;
				cout << "Current Speed: " << Vehicle1.accelerate() << endl;
			}
		else if(input == 2)
			{
				cout << "You have chosen to deaccelerate" << endl;
				cout << "Current Speed: " << Vehicle1.brake() << endl;
			}
		else if(input == 3)
			{
				cout << "You have chosen to turn off and exit the vehicle" << endl;
				running = true;
			}
	}

	cout << "FINAL DETAILS: " << endl;
	Vehicle1.displayDetails();
	cout << endl;

	system("Pause");
}