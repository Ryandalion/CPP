#include <iostream>
#include <string>
#include "character.hpp"

using std::getline;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	CharConverter input;	// CharConverter object

	string sentence;		// String to hold original sentence
	string uppercase;		// Uppercase ==> uppercase sentence
	string firstletter;		// firstletter ==> starting letter of every word is uppercase

	bool running = false;	// Bool to determine if user wants to enter another word

	cout << "Welcome to the Character Converter" << endl;
	cout << "This program has two functions" << endl;
	cout << "1. Uppercase all lowercase letters" << endl;
	cout << "2. Uppercases each starting letter of individual words" << endl;
	cout << endl;
	
	while (running != true)
	{	
		cout << "Please enter a string that you want to convert: ";
		cin.ignore();
		getline(cin, sentence);

		uppercase = input.uppercase(sentence);
		firstletter = input.properWords(sentence);

		cout << endl;
		cout << uppercase << endl;
		cout << firstletter << endl;
		cout << endl;

		cout << "Would you like to enter another string?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		int decision = 0;
		cin >> decision;
		if (decision == 1)
		{
			running = false;
			
		}
		else
			running = true;
	}

	system("pause");


}