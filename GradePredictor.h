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

public:

	void readFiles();
	void printSummary();
	void printReport();
	void addCategory(Category c);
	void editCategory();
};
#endif
