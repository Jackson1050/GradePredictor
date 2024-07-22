#include "Category.h"
#include "Assignment.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Category::Category()
{
	totalWeight = 0.0;
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

Assignment Category::newInfo(Assignment a)
{
	string tempName;
	int tempPP;
	int tempPE;
	bool tempISC;
	system("CLS");

	cout << "Enter assignment name: " << endl;
	cin >> tempName;
	a.setNameA(tempName);

	cout << "Enter points earned: " << endl;
	cin >> tempPE;
	a.setPointsE(tempPE);

	cout << "Enter points possible: " << endl;
	cin >> tempPP;
	a.setPointsP(tempPP);

	cout << "Is assignment completed? (1 for yes, 0 for no): " << endl;
	cin >> tempISC;
	a.setIsComplete(tempISC);

	return a;
}

Assignment Category::editAssignment(Assignment a)
{
	string tempName;
	int tempPP;
	int tempPE;
	bool tempISC;
	system("CLS");

	cout << "Enter assignment name: " << endl;
	cin >> tempName;
	a.setNameA(tempName);

	cout << "Enter points earned: " << endl;
	cin >> tempPE;
	a.setPointsE(tempPE);

	cout << "Enter points possible: " << endl;
	cin >> tempPP;
	a.setPointsP(tempPP);

	cout << "Is assignment completed? (1 for yes, 0 for no): " << endl;
	cin >> tempISC;
	a.setIsComplete(tempISC);

	a.setIsEdited(true);

	return a;
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