#include "Assignment.h"

#include <string>
#include <iostream>

using namespace std;

Assignment::Assignment()
{
	isEdited = false;
}

string Assignment::getNameA()
{
	return nameA;
}

void Assignment::setNameA(string nA)
{
	nameA = nA;
}

int Assignment::getPointsE()
{
	return pointsE;
}

void Assignment::setPointsE(int pE)
{
	pointsE = pE;
}

int Assignment::getPointsP()
{
	return pointsP;
}

void Assignment::setPointsP(int pP)
{
	pointsP = pP;
}

bool Assignment::getIsComplete()
{
	return isComplete;
}

void Assignment::setIsComplete(bool isC)
{
	isComplete = isC;
}

bool Assignment::getIsEdited()
{
	return isEdited;
}

void Assignment::setIsEdited(bool isE)
{
	isEdited = isE;
}

string Assignment::getAssignmentInfo()
{
	string complete;
	string edited;

	if (isComplete)
	{
		complete = "Yes";
	}
	else
	{
		complete = "No";
	}

	if (isEdited)
	{
		edited = "Yes";
	}
	else
	{
		edited = "No";
	}

	string infoA = "Name: " + nameA + "\n" + "Points: " + to_string(pointsE) + "/" + to_string(pointsP) +
		"\n" + "Complete?: " + complete + "\n" + "Edited?: " + edited;
}
