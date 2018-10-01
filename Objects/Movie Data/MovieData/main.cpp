#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

struct MovieData
{
	string title;
	string director;
	int year_released;
	int running_time;
	MovieData();
};

MovieData::MovieData()
{
	title = "";
	director = "";
	year_released = 0;
	running_time = 0;
}

void displayMovieStats(MovieData);

int main()
{
	string moviename;

	cout << "Welcome to the Movie Data Base" << endl;
	cout << "Here are the details of film" << endl;
	MovieData m1, m2, m3;

	cout << "Enter movie name: " << endl;
	cin >> moviename;
	m1.title = moviename;
	m2.title = "Steel Divison";
	m3.title = "Skyrim";

	m1.director = "Warhorse";
	m2.director = "Paradox";
	m3.director = "Bethesda";

	m1.year_released = 2018;
	m2.year_released = 2018;
	m3.year_released = 2008;

	m1.running_time = 1000;
	m2.running_time = 500;
	m3.running_time = 8000;

	cout << endl;
	displayMovieStats(m1);
	cout << endl;
	displayMovieStats(m2);
	cout << endl;
	displayMovieStats(m3);

	system("pause");

}

void displayMovieStats(MovieData movie)
{
	cout << "Movie Name: " << movie.title << endl;
	cout << "Movie Director: " << movie.director << endl;
	cout << "Year Released: " << movie.year_released << endl;
	cout << "Running Time: " << movie.running_time << " minutes" << endl;
}