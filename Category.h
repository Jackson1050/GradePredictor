#ifndef CATEGORY_H
#define CATEGORY_H

#include "Assignment.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Category
{

private:

	
	string nameC;
	double totalWeight;
	double predGradeRem;

public:
	vector <Assignment> Assignments{};
	Category();
	string getName();
	void setName(string nC);
	void addAssignment(Assignment a);
	Assignment newInfo(Assignment a);
	Assignment editAssignment(Assignment a);
	double getWeight();
	void setWeight(double w);
	int getAComplete(Category c);
	int getARemaining(Category c);
	double getGrade(Category c);
	double getPredGrade(Category c);
	double getAverage(Category c);
	int getTotalPoints();


};
#endif
