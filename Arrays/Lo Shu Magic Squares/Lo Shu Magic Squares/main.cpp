#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

void shuffleMagicSquare(int square[][3], int numbers[]);						// Place shuffled numbers into square array
bool isMagicSquare(int square[][3]);											// Check if array is magic square

int main()
{
	srand(time(NULL));

	int numbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };								// Array filled with the digits 0 - 9
	int square[3][3];															// 3 x 3 array for magic square
	

	std::random_shuffle(numbers, numbers + 9);									// Shuffle numbers array
	
	cout << "Welcome to Lo Shu Magic Square" << endl;
	cout << "Let's generate some random numbers and place them in a square" << endl;

	shuffleMagicSquare(square, numbers);										// Place shuffled numbers into the square array

	for (int i = 0; i < 3; i++)													// Output the 3x3 square
	{
		for (int j = 0; j < 3; j++)
		{
			cout << square[i][j] << " ";
		}
		cout << endl;
	}
	
	if (isMagicSquare(square))													// If function returns true print
		cout << "It is a magic square!" << endl;
	else
		cout << "It is not a magic square" << endl;								// Else do not

	system("pause");
}

void shuffleMagicSquare(int square[][3], int numbers[])							// Place shuffled numbers into square array
{
	int numberindex = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			square[i][j] = numbers[numberindex];
			numberindex++;
		}
	}
}

bool isMagicSquare(int square[][3])												// Check if square array is a magic square
{
	int sum = 0;
	int row = 0;
	int col = 0;

	for (int i = 0; i < 3; i++)													// Diagonal Check and set sum equal to the diagonal sum
		sum = sum + square[i][i];

	for (int i = 0; i < 3; i++)													// Check columns and see if it is equal to sum
	{
		col = 0;
		for (int j = 0; j < 3; j++)
		{
			col = col + square[j][i];
		}
	}
	
	if (col != sum)																// If columns is not equal to sum, return false
	{
		return false;
	}

	for (int i = 0; i < 3; i++)													// Check rows and see if it is equal to sum
	{
		row = 0;
		for (int j = 0; j < 3; j++)
			row = row + square[i][j];
	}
	
	if (row != sum)																// If rows is not equal to sum, return false
	{
		return false;
	}

	return true;																// Else if everything passes return true
}