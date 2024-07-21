#include "Assignment.h"
#include "Category.h"
#include "GradePredictor.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void GradePredictor::readFiles()
{
	string Atext;
	string Ctext;
	int number;
	bool binary;
	bool exists = false;
	ifstream inputFile;
	
	Assignment a;
	Category c;
	Category t;
	Category Homework;
	Homework.setName("Homework");
	Categories.push_back(Homework);

	inputFile.open("Assignments.txt");
	inputFile >> Ctext;
	while (!(inputFile.eof()))
	{
		for (int i = 0; i < Categories.size(); i++) 
		{
			for (int k = 0; k < Categories.size(); k++)
			{
				t = Categories[k];
				if (Ctext == t.getName())
				{
					exists = true;
					break;
				}
				else
				{
					exists = false;
				}
			}
			if ((exists == false) || (Categories.size() == 0)) //make a new category if needed
			{
				Category category;
				category.setName(Ctext);
				Categories.push_back(category);
			}

			for (int j = 0; j < Categories.size(); j++)
			{
				c = Categories[j];
				if (c.getName() == Ctext)
				{
					a.setGroup(Ctext);

					inputFile >> Atext;
					a.setNameA(Atext);

					inputFile >> number;
					a.setPointsE(number);

					inputFile >> number;
					a.setPointsP(number);


					inputFile >> binary;
					a.setIsComplete(binary);
					c.Assignments.push_back(a);
					
				}
				Categories[j] = c;
				
			}
			inputFile >> Ctext;


		}
		
	}
}

void GradePredictor::printSummary()
{
	
}

void GradePredictor::printReport()
{
	for (Category c : Categories)
	{
		for (Assignment a : c.Assignments)
		{
			cout << a.getAssignmentInfo() << endl << endl;;
		}
	}
}

void GradePredictor::addCategory(Category c)
{

}

void GradePredictor::editCategory()
{

}





