#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Student // Struct to hold student data
{
	string name;
	double score;
	Student();
};

Student::Student() // Struct default constructor
{
	name = " ";
	score = 0;
}

void sortData(Student student[], int num);
void calcAverage(Student student[], int num);

int main()
{
	int num = 0;
	string name;
	int score;
	double average;

	Student *student; // Pointer of the struct student
	Student *pointer;

	cout << "Test Grade Database" << endl;
	cout << "Enter the student's name followed by their score" << endl;
	cout << "How many student's information will you be submitting today? " << endl;
	cin >> num;

	student = new Student[num]; // Student is a pointer to an array of Student structs
	pointer = student;
	cout << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "Enter the name of student #" << i + 1 << ": ";
		cin >> (pointer + i)->name;
		cout << "Enter the score for " << name << ": ";
		cin >> (pointer + i)->score;
		cout << endl;
	}

	calcAverage(pointer, num); // Pass the Student array that contains the struct of students and pass the num
	sortData(pointer, num);
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout << student[i].name << " " << student[i].score << endl;
	}



	delete[] student;

	system("pause");
}


void sortData(Student student[], int num) 
{
	Student *pointer = student; // Pointer to student array struct

	Student swap;

	for (int i = 0; i < num; i++)
	{
		for (int k = i + 1; k < num; k++)
		{
			if ((pointer + i)->score > (pointer + k)->score)
			{
				swap = *(pointer + i);
				*(pointer + i) = *(pointer + k);
				*(pointer + k) = swap;
			}
		}
	}
}

void calcAverage(Student pointer[], int num) // Calculate the average, @Param includes an array of struct Student and num
{
	double average = 0; // Set average to zero
	Student *person = pointer; // Create a new struct pointer that points to the array of student structs

	for (int i = 0; i < num; i++)
	{
		average = average + (person + i)->score; // Person starts off at index 0 so 0 + 0 = Student student[0] -> score
	}

	 average = (average / num);
	 cout << average << endl;
}