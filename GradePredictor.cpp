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
	string repBlock;
	int number;
	bool binary;
	bool exists = false;
	ifstream inputFile;
	
	Assignment a;
	Category c;
	Category t;
	GradePredictor GP;
	
	//Make default category to fill vector / test with
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
					if (a.getIsComplete() == false)
					{
						a.setPointsE(0);
					}

					if (a.getNameA() != repBlock)
					{
						c.Assignments.push_back(a);
						
					}
					repBlock = a.getNameA();
				}
				Categories[j] = c;
				
			}
			inputFile >> Ctext;


		}
		
	}
}

void GradePredictor::printSummary()
{
	system("CLS");
	double classGrade = 0;
	Category c;
	for (int i = 0; i < Categories.size(); i++)
	{
		c = Categories[i];
		cout << "Category: " << Categories[i].getName() << endl;
		cout << "Grade: " << Categories[i].getGrade(c) << endl;
		cout << "Total Weight: " << Categories[i].getWeight() << endl;
		classGrade = classGrade + (Categories[i].getGrade(c) * Categories[i].getWeight());
		
	}
	cout << "Predicted Grade for Class: " << classGrade << endl;
	cout << "Press any key and ENTER to return to main menu" << endl;
	cin >> input;
	mainMenu();

	

}

void GradePredictor::printReport()
{
	Category c;
	cout << "Select which category to print report of: " << endl;
	for (int i = 0; i < Categories.size(); i++)
	{
		cout << to_string((i + 1)) << ". " << Categories[i].getName() << endl;
	}
	cin >> choice;
	while ((choice < 1) || (choice > Categories.size()))
	{
		cin >> choice;
	}
	c = Categories[choice - 1];

	system("CLS");
	cout << c.getName() << endl;
	cout << "Category Weight: " << c.getWeight() << endl;
	cout << "Assignments Completed: " << c.getAComplete(c) << endl;
	cout << "Assignments Remaining: " << c.getARemaining(c) << endl;
	cout << "Current Grade: " << c.getGrade(c) << endl;
	cout << "Expected Grade on Unfinished Assignments: " << c.getAverage(c) << endl;
	cout << "Predicted Grade for Category: " << c.getPredGrade(c) << endl;
	cout << endl;

	for (Assignment a : c.Assignments)
	{
		cout << a.getAssignmentInfo() << endl << endl;;
			
	}

	cout << "Press any key and ENTER to return to main menu" << endl;
	cin >> input;
	mainMenu();
}

Category GradePredictor::addCategory(Category c)
{
	Category category;
	string temp;
	system("CLS");
	cout << "Enter category name: ";
	cin >> temp;
	category.setName(temp);
	c = category;
	return c;
	
}

void GradePredictor::editCategory()
{

}

void GradePredictor::mainMenu()
{
	system("CLS");
	cout << "GRADE PREDICTOR" << endl;
	cout << "Select an option: " << endl;
	cout << "1. Class Grade Summary" << endl;
	cout << "2. Category Summary" << endl;
	cout << "3. Edit Category" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		for (int i = 0; i < Categories.size(); i++)
		{
			totalWeight = totalWeight + Categories[i].getWeight();
		}
		if (totalWeight == 1.0)
		{
			printSummary();
		}
		else
		{
			cout << "Total Weights do not add up to 1. Edit your category weights first." << endl;
			cout << "Press any key and ENTER to return to main menu" << endl;
			cin >> input;
			mainMenu();
		}
		break;

	case 2:
		
		printReport();
		break;

	case 3:
		catMenu();
		break;

	default:
		mainMenu();
		break;
	}



}

void GradePredictor::catMenu()
{

	GradePredictor g;
	Category c;

	system("CLS");
	cout << "CATEGORY MENU" << endl;
	cout << "0. Return to main menu" << endl;;
	cout << "1. Add category" << endl;
	cout << "CATEGORIES: " << endl;
	for (int i = 0; i < Categories.size(); i++)
	{
		cout << to_string(i + 2) + ". " + Categories[i].getName() << endl;
	}
	cout << "Choose Category to edit: " << endl;
	cin >> choice;
	while ((choice < 0) || (choice > (Categories.size() + 1)))
	{
		cin >> choice;
	}
	catInd = (choice - 2);
	switch (choice)
	{
	case 0:

		mainMenu();
		break;

	case 1:
		c = g.addCategory(c);
		Categories.push_back(c);
		catMenu();
		break;

	default:
		assignMenu();
	}
}

void GradePredictor::assignMenu()
{
	Assignment a;
	system("CLS");
	cout << "ASSIGNMENT MENU" << endl;
	cout << "Category: " << Categories[catInd].getName() << endl;
	cout << "Category weight: " << Categories[catInd].getWeight() << endl;
	Category c = Categories[(catInd)];

	cout << "0. Return to categories menu" << endl;
	cout << "1. Edit category weight" << endl; 
	cout << "2. Add assignment" << endl;
	cout << "ASSIGNMENTS: " << endl;
	for (int i = 0; i < c.Assignments.size(); i++)
	{
		cout << to_string(i + 3) + ". " + c.Assignments[i].getNameA() << endl;
	}
	cout << "Choose assignment to edit: " << endl;
	cin >> choice;
	if (c.Assignments.size() == 0)
	{
		while ((choice < 0) || (choice > 2))
		{
			cin >> choice;
		}
	}
	else
	{
		while ((choice < 0) || (choice > c.Assignments.size() - 1))
		{
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 0: 

		catMenu();
		break;

	case 1:
		double temp;
		system("CLS");
		cout << "Enter category weight (percent as decimal value): " << endl;
		cin >> temp;
		Categories[catInd].setWeight(temp);
		assignMenu();
		break;

	case 2:
		
		a = Categories[catInd].newInfo(a);
		Categories[catInd].Assignments.push_back(a);
		assignMenu();
		break;


	default:

		Categories[catInd].Assignments[(choice - 3)] = c.editAssignment(c.Assignments[(choice - 3)]);
		assignMenu();
	}
}





