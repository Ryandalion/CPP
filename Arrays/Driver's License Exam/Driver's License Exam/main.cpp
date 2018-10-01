#include <iostream>
#include <string>

#include "TestGrader.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	TestGrader test; // TestGrader object to be used to call function

	char answer; // Administrator's input
	char studentAnswer; // Student's input 
	char answerKey[20] = { " " }; // Array to hold the solutions per input by administrator
	char student[20] = { " " }; // Array to hold the student's answers
	
	cout << "Driver's License Exam System" << endl;
	cout << "Please enter the test keys for the exam" << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << "Question " << i + 1 << ": ";
		cin >> answer;
		while (!((answer >= 'a' && answer <= 'd') || (answer >= 'A' && answer <= 'D'))) // If input is not within range (ASCII) , then it is invalid
		{
			cout << "Invalid Input. Please enter a letter between A - D" << endl;
			cin >> answer;
		}

		answerKey[i] = answer; // Store answer into answer key array
	}

	for (int i = 0; i < 20; i++)
	{
		answerKey[i] = toupper(answerKey[i]); // Upper case all elements in array to make it easier to check for correct answer
	}

	test.setKey(answerKey); // Send the answerKey array to bet set 

	cout << "Please enter the student's answers" << endl; // Retrieve student's answers
	for (int i = 0; i < 20; i++)
	{
		cout << "Question " << i + 1 << ": ";
		cin >> studentAnswer;
		while (!((studentAnswer >= 'a' && studentAnswer <= 'd') || (studentAnswer >= 'A' && studentAnswer <= 'D'))) // If input is not within range (ASCII) , then it is invalid
		{
			cout << "Invalid Input. Please enter a letter between A - D" << endl;
			cin >> studentAnswer;
		}
	
		student[i] = studentAnswer;	// Store the answer in student array
	}

	for (int i = 0; i < 20; i++) // Upper case all elements in student array to make it easier for processing
	{
		student[i] = toupper(student[i]);
	}

	test.grade(student); // Send student array to be evaluated

	system("pause");

}