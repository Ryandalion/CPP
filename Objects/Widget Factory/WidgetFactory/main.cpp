#include <iostream>
#include <string>
#include <istream>
#include "widget.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int num;
	Widget order_1;
	cout << "Welcome to the Widget Shop" << endl;
	cout << "We produce 10 widgets per hour." << endl;
	cout << "We operate 16 hours per day." << endl;
	cout << "Please enter the number of widgets you wish to manufacture: " << endl;
	cin >> num;

	order_1.setCount(num);
	cout << endl;
	cout << "Your order of " << num << " widgets, will take " << order_1.Calculate() << " days to manufacture." << endl;
	cout << endl;

	system("Pause");
}