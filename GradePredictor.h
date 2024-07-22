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
	int catInd = 0;

public:

	void readFiles();
	void printSummary();
	void printReport();
	Category addCategory(Category c);
	void editCategory();
	void mainMenu();
	void catMenu();
	void assignMenu();
};
#endif
