#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Assignment
{
private:

	string nameA;
	string group;
	int pointsP;
	int pointsE;
	bool isComplete;
	bool isEdited;

public:
	Assignment();
	string getNameA();
	void setNameA(string nA);
	int getPointsE();
	void setPointsE(int pE);
	int getPointsP();
	void setPointsP(int pP);
	bool getIsComplete();
	void setIsComplete(bool isC);
	bool getIsEdited();
	void setIsEdited(bool isE);
	string getGroup();
	void setGroup(string gr);
	string getAssignmentInfo();
};
#endif
