#ifndef GRADEPREDICTOR_H
#define GRADEPREDICTOR_H

#include "Assignment.h"
#include "Category.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class GradePredictor
{
private:

	vector <Category> Categories {};
	double predClassGrade;
	int index;
	int choice;
	char input;
	int catInd = 0;
	double totalWeight = 0.0;

public:

	void readFiles();
	void printSummary();
	void printReport();
	Category addCategory(Category c);
	void mainMenu();
	void catMenu();
	void assignMenu();
};
#endif
