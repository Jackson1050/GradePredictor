#include "Category.h"
#include "Assignment.h"

#include <string>
#include <iostream>
#include <vector>

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
void Category::addAssignment()
{

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

}

int Category::getARemaining()
{

}

double Category::getGrade()
{

}

double Category::getPredGrade()
{

}

int Category::getTotalPoints()
{

}