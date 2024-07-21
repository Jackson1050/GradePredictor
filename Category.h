#ifndef CATEGORY_H
#define CATEGORY_H

#include "Assignment.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Category
{

private:

	vector <Assignment> Assignments;
	string nameC;
	double totalWeight;
	double predGradeRem;

private:

	Category();
	string getName();
	void setName(string nC);
	void addAssignment();
	void editAssignment();
	double getWeight();
	void setWeight(double w);
	int getAComplete();
	int getARemaining();
	double getGrade();
	double getPredGrade();
	int getTotalPoints();


};
#endif
