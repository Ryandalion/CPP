#include <iostream>
#include <string>
#include <time.h>

using std::string;

#ifndef COIN_H
#define COIN_H

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