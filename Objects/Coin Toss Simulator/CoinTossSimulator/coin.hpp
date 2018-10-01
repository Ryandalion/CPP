#include <iostream>
#include <string>
#include <time.h>

#ifndef COIN_H
#define COIN_H

using std::cout;
using std::endl;
using std::string;

class Coin
{
public:
	Coin();
	~Coin();

	void toss();
	string getSideUp();

private:
	string sideUp;

};

#endif