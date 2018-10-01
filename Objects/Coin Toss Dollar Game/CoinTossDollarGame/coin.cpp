#include "coin.hpp"

Coin::Coin()
{
	int side = rand() % 2 + 1;
	if (side == 1)
	{
		sideUp = "Heads";
	}
	else
	{
		sideUp = "Tails";
	}
}

void Coin::toss()
{
	int side = rand() % 2 + 1;
	if (side == 1)
	{
		sideUp = "Heads";
	}
	else
	{
		sideUp = "Tails";
	}
}

string Coin::getSideUp()
{
	return sideUp;
}


Coin::~Coin()
{

}
