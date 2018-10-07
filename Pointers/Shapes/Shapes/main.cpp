#include <iostream>
#include <string>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Shape
{
public:
	void get_data(double length, double height)
	{
		this->length = length;
		this->height = height;
	}
	virtual void display_area()
	{
	}

	double length = 0;
	double height = 0;
	double area;
};

class triangle : public Shape
{
public:
	void display_area()
	{
		area = (.5) * length * height;
		cout << "The area of the triangle is " << area << endl;
	}
private:

};

class rectangle : public Shape
{
public:
	void display_area()
	{
		area = length * height;
		cout << "The area of the rectangle is " << area << endl;
	}
private:

};

class circle : public Shape
{
public:
	void display_area()
	{
		area = (3.14) *(std::pow(length, 2));
		cout << "The area of the circle is " << area << endl;
	}
private:

};

int main()
{
	Shape userShape;
	triangle userTriangle;
	rectangle userRectangle;
	circle userCircle;
	Shape *pointer;
	
	pointer = &userTriangle;

	pointer->get_data(3, 3);
	pointer->display_area();

	pointer = &userRectangle;
	pointer->get_data(5, 3);
	pointer->display_area();

	pointer = &userCircle;
	pointer->get_data(3,0);
	pointer->display_area();


	system("pause");
	return 0;
}