#include "character.hpp"

CharConverter::CharConverter()
{
	convertedString = " ";
}

string CharConverter::uppercase(string sentence)
{
	for (int i = 0; i < sentence.length(); i++)		// Loop through length of sentence
	{
		if (islower(sentence[i]))					// If character is lower then upper the letter at index i
		{
			sentence[i] = toupper(sentence[i]);

		}
	}

	return sentence;
}

string CharConverter::properWords(string sentence)
{
	if (islower(sentence[0]))						// Check first character of sentence and determine if it is lowercase. If it is lowercase convert it to uppercase
	{
		sentence[0] = toupper(sentence[0]);
	}

	for (int i = 1; i < sentence.length(); i++)	 // Loop through sentence and see if index - 1 is a space, then convert the char at index i to uppercase
	{
		if (sentence[i - 1] == ' ')
		{
			sentence[i] = toupper(sentence[i]);
		}
	}
	return sentence;
}

CharConverter::~CharConverter()
{

}