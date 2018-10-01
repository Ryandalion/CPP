#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string romanNumeral[20] = { "I", "II", "III", "IV", "V", "VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV", "XVI", "XVII", "XVIII", "XIX", "XX" };
	int userInput = -1;

	cout << "This program will match a user input integer with a Roman Numeral equivalent" << endl;
	cout << "Please enter values between 0 and 20" << endl;

	while (userInput != 0)
	{
		cout << "Enter a number or enter zero to exit: " << endl;
		cin >> userInput;
		
		if (userInput == 0)
		{
			break;
		}

		if (userInput > 20 || userInput < 0)
		{
			cout << "Enter a value between 0 and 20: " << endl;
			cin >> userInput;
		}
		
		cout << "The Roman Numeral equivalent is: " << endl;
		cout << romanNumeral[userInput - 1] << endl;
	}
	
	return 0;
	system("pause");
}