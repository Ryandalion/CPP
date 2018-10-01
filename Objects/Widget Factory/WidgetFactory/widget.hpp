#include <iostream>

#ifndef WIDGET_H
#define WIDGET_H

class Widget 
{
public:
	Widget();
	~Widget();

	void setCount(int numwidge);			// Set number of widgets
	int Calculate();						// Calculate the widgets

private:
	int units;

};





#endif
