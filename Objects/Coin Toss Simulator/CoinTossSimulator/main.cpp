#include <iostream>
#include "coin.hpp"

using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));

	Coin c1;
	int heads = 0;
	int tails = 0;

	cout << "This is a coin toss simulator" << endl;
	cout << "Side that is currently facing up: " << c1.getSideUp() << endl;
	cout << endl;
	cout << "We will now execute 20 coin flips" << endl;
	cout << endl;
	for (int i = 0; i < 20; i++)
	{
		c1.toss();
		cout << "Side that is currently facing up after coin toss number " << i + 1 << ":  " << c1.getSideUp() << endl;
		if (c1.getSideUp() == "Heads")
		{
			heads++;
		}
		else if (c1.getSideUp() == "Tails")
		{
			tails++;
		}
	}

	cout << endl;
	cout << "Final Count: " << endl;
	cout << "HEADS: " << heads << endl;
	cout << "TAILS: " << tails << endl;

	system("pause");
}