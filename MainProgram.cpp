//Jackson Hill
//Grade Predictor

#include "Assignment.h"
#include "Category.h"
#include "GradePredictor.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	GradePredictor GP;

	GP.readFiles(); //reads assignments from txt file
	GP.mainMenu(); //runs program

	return 0;
}
