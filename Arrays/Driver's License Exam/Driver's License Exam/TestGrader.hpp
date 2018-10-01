#include <iostream>
#include <string>
#include <vector>

#ifndef TESTGRADER_H
#define TESTGRADER_H

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class TestGrader 
{
public:
	
	TestGrader();
	void setKey(char answerKey[]);
	void grade(char student[]);
	~TestGrader();

private:
	char answers[20]; // Array to hold the answer key from administrator
};

#endif