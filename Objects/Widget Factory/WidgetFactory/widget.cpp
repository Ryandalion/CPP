#include "widget.hpp"

Widget::Widget() 
{
	units = 0;
}

void Widget::setCount(int numwidge)
{
	units = numwidge;
}

int Widget::Calculate()
{
	int day = 1;
	int total = 0;
	int time = 0;
	bool valid = false;

	total = (units * 6);				// Total minutes it takes to create all widgets
	while (valid != true)				// Loop until valid is false
	{
		if (total > 960)				// If total exceeds the maximum amount the factory is open (in minutes)
		{
			day++;						// Increase day
			total = total - 960;		// Subtract total manufactured from remaining
		}
		else                            // If total is less than 960 minutes
		{
			valid = true;				// Change valid to true to exit while loop 
		}
	}

	return day;							// Return the number of days
}

Widget::~Widget()
{

}