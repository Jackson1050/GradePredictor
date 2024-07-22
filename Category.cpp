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
	if (tempISC = false)
	{
		a.setPointsE(0);
	}

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

int Category::getAComplete(Category c)
{
	int count = 0;
	for (int i = 0; i < c.Assignments.size(); i++)
	{
		if (c.Assignments[i].getIsComplete() == true)
		{
			count++;
		}
	}
	return count;
}

int Category::getARemaining(Category c)
{
	int count = 0;
	for (int i = 0; i < c.Assignments.size(); i++)
	{
		if (c.Assignments[i].getIsComplete() == false)
		{
			count++;
		}
	}
	return count;
}

double Category::getGrade(Category c)
{
	double totalPP = 0;
	double totalPE = 0;

	for (int i = 0; i < c.Assignments.size(); i++)
	{
		if (c.Assignments[i].getIsComplete())
		{
			totalPP = totalPP + c.Assignments[i].getPointsP();
			totalPE = totalPE + c.Assignments[i].getPointsE();
		}
	}

	return (totalPE / totalPP) * 100;
}

double Category::getAverage(Category c)
{
	double total = 0;
	int count = 0;
	for (int i = 0; i < c.Assignments.size(); i++)
	{
		if (c.Assignments[i].getIsComplete() == true)
		{
			count++;
			total = total + ((static_cast<double>(c.Assignments[i].getPointsE()) / c.Assignments[i].getPointsP()) * 100);
		}
	}
	double average = (total / count);
	return average;
}

double Category::getPredGrade(Category c)
{
	
	double expectedGrade = c.getAverage(c);
	double actualGrade = c.getGrade(c);

	return (expectedGrade + actualGrade) / 2;

}

int Category::getTotalPoints()
{
	return 0;
}