#include "Category.h"
#include "Assignment.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Category::Category()
{
	
}

string Category::getName()
{
	return nameC;
}

void Category::setName(string nC)
{
	nameC = nC;
}
void Category::addAssignment(Assignment a)
{
	Assignments.push_back(a);

}

void Category::editAssignment()
{

}

double Category::getWeight()
{
	return totalWeight;
}
void Category::setWeight(double w)
{
	totalWeight = w;
}

int Category::getAComplete()
{
	return 0;
}

int Category::getARemaining()
{
	return 0;
}

double Category::getGrade()
{
	return 0.0;
}

double Category::getPredGrade()
{
	return 0.0;
}

int Category::getTotalPoints()
{
	return 0;
}