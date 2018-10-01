#include <iostream>
#include <string>

using std::string;

class Fish
{
public:
	Fish();
	~Fish();

	string objectname();
	void setType();
	void setStats();
	double totalPoints();
	void rolldice();
	double displayPoints();

private:
	string name;
	int type;
	int points;
	int roll;
};