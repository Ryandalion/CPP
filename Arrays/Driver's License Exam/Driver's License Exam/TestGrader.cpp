#include "TestGrader.hpp""

TestGrader::TestGrader()	// Constructor. Intialize all elements to zero
{
	for (int i = 0; i < 20; i++)
	{
		answers[i] = 0;
	}
}

void TestGrader::setKey(char answerKey[]) // Put answers into answer array
{
	for (int i = 0; i < 20; i++)
	{
		answers[i] = answerKey[i];
	}
}

void TestGrader::grade(char student[])	// Get student answers
{
	int correct = 0;	// Number of questions correct
	int wrong = 0;		// Number of questions wrong
	vector<int> index;	// Store the question numbers that the student got wrong
	string pass;		// Pass or fail string

	for (int i = 0; i < 20; i++)	// Compare answer key to student key
	{
		if (answers[i] == student[i]) // If answer is correct, increment number of correct answers
		{
			correct++;
		}
		else //If answer is wrong, increment wrong counter and push the index number to the vector
		{
			wrong++;
			index.push_back(i);
		}
	}

	if (correct >= 15)  // If correct answers is 15 or over, then the student has passed
	{
		pass = "has passed";
	}
	else // If correct answers is below 15, then student has not passed
	{
		pass = "has not passed";
	}


	cout << "The student " << pass << " the exam." << endl;
	cout << "Correct Number of Answers: " << correct << endl;
	cout << "Wrong Number of Answers: " << wrong << endl;
	cout << "The question numbers the student got wrong are ";

	for (int i = 0; i < index.size(); i++) // Print the question numbers the student got wrong
	{

		cout << index[i] + 1 << ", ";
	}
	
	cout << endl;
}

TestGrader::~TestGrader()
{

}