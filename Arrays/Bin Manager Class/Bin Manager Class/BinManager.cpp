#include "BinManager.hpp"

BinManager::BinManager()
{
	numBins = 0;
}

BinManager::BinManager(int size, string d[], int q[]) // Intialize the quantity of bins and add the name and quantity of each item respectively
{
	for (int i = 0; i < size; i++)
	{
		bin[i].setDescription(d[i]); // Set description of item at bin index i
		bin[i].setQty(q[i]); // Set quantity of item at bin index i
	}

	numBins = size; // Update bin size
}

string BinManager::getDescription(int index) // Return name of item
{
	return bin[index].getDescription();
}

int BinManager::getQuantity(int index) // Return the quantity of item
{
	return bin[index].getQty();
}

bool BinManager::addParts(int binIndex, int q) // Add parts to item; Desired quantity to add must exceed 1
{
	if (q < 1) // If user wants to add less than 1 part, then return false
	{
		return false;
	}

	else // Else user wants to add 1 or more parts and execute the function below
	{
		binIndex = binIndex - 1; // Reinitialize index to correspond to array
		bin[binIndex].setQty(bin[binIndex].getQty() + q); // Set the new quantity by adding the quantity the user wishes to add
		return true; // Return true
	}
}

bool BinManager::removeParts(int binIndex, int q) // Remove parts from item
{
	binIndex = binIndex - 1; // Reinitialize index to correspond to array
	if (q > bin[binIndex].getQty()) // If user quantity of removal exceeds current quantity of item return false
	{
		cout << "Remove quantity exceeds quantity in stock" << endl;
		return false;
	}

	else if(bin[binIndex].getQty() < 1) // If user wants to remove less than one item return false
	{
		cout << "Quantity must be greater than 1" << endl;
		return false;
	}

	else // If pass all tests above, then execute removal of desired quantity from current quantity
	{
		bin[binIndex].setQty(bin[binIndex].getQty() - q);
		return true;
	}
}

BinManager::~BinManager()
{

}