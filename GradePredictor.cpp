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

	inputFile.open("Assignments.txt"); //open txt file
	inputFile >> Ctext; //read category name
	while (!(inputFile.eof())) //check to see if there are more assignments in file to read
	{
		for (int i = 0; i < Categories.size(); i++) //ensure we do not access nonexistent categories
		{
			for (int k = 0; k < Categories.size(); k++) //tests if the category exists already
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

			for (int j = 0; j < Categories.size(); j++)//ensure we are not accessing nonexistent categories
			{
				c = Categories[j];
				if (c.getName() == Ctext)//place assignment in correct category
				{
					a.setGroup(Ctext);//set assignment's category

					inputFile >> Atext;
					a.setNameA(Atext);//set assignment's name

					inputFile >> number;
					a.setPointsE(number);//set assignment's points earned

					inputFile >> number;
					a.setPointsP(number);//set assignment's points possible

					inputFile >> binary;
					a.setIsComplete(binary);//set assignment's completion status

					if (a.getIsComplete() == false)//set points to 0 if assignment is incomplete
					{
						a.setPointsE(0);
					}

					if (a.getNameA() != repBlock)//make sure we do not create duplicate assignments
					{
						c.Assignments.push_back(a);
						
					}
					repBlock = a.getNameA();//update repeat assignment checker
				}
				Categories[j] = c;//add assignment to category
				
			}
			inputFile >> Ctext; //read next category name


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
		c = Categories[i]; //display information about each category
		cout << "Category: " << Categories[i].getName() << endl;
		cout << "Grade: " << Categories[i].getGrade(c) << endl;
		cout << "Total Weight: " << Categories[i].getWeight() << endl;
		classGrade = classGrade + (Categories[i].getGrade(c) * Categories[i].getWeight()); //update class grade based on category info
		
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
	{ //print list of all available categories
		cout << to_string((i + 1)) << ". " << Categories[i].getName() << endl;
	}
	cin >> choice;
	while ((choice < 1) || (choice > Categories.size()))//input validation
	{
		cin >> choice;
	}
	c = Categories[choice - 1];//set category based on input

	system("CLS");//print all info about selected category
	cout << c.getName() << endl;
	cout << "Category Weight: " << c.getWeight() << endl;
	cout << "Assignments Completed: " << c.getAComplete(c) << endl;
	cout << "Assignments Remaining: " << c.getARemaining(c) << endl;
	cout << "Current Grade: " << c.getGrade(c) << endl;
	cout << "Expected Grade on Unfinished Assignments: " << c.getAverage(c) << endl;
	cout << "Predicted Grade for Category: " << c.getPredGrade(c) << endl;
	cout << endl;

	for (Assignment a : c.Assignments)//print all info about all assignments in selected category
	{
		cout << a.getAssignmentInfo() << endl << endl;;
			
	}

	cout << "Press any key and ENTER to return to main menu" << endl;
	cin >> input;
	mainMenu();
}

Category GradePredictor::addCategory(Category c)
{ //allow user to add category and store it in categories vector
	Category category;
	string temp;
	system("CLS");
	cout << "Enter category name: ";
	cin >> temp;
	category.setName(temp);
	c = category;
	return c;
	
}


void GradePredictor::mainMenu()
{
	system("CLS");//print out menu options
	cout << "GRADE PREDICTOR" << endl;
	cout << "Select an option: " << endl;
	cout << "1. Class Grade Summary" << endl;
	cout << "2. Category Summary" << endl;
	cout << "3. Edit Category" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1://CLASS GRADE SUMMARY
		for (int i = 0; i < Categories.size(); i++)//add up total weights
		{
			totalWeight = totalWeight + Categories[i].getWeight();
		}
		if (totalWeight == 1.0)//ensure total weights add up to 1
		{
			printSummary();
		}
		else
		{//tell user to update weights
			cout << "Total Weights do not add up to 1. Edit your category weights first." << endl;
			cout << "Press any key and ENTER to return to main menu" << endl;
			cin >> input;
			mainMenu();
		}
		break;

	case 2: //PRINT CATEGORY REPORTS
		
		printReport();
		break;

	case 3:
		catMenu(); //EDIT CATEGORIES
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

	system("CLS");//Display menu options
	cout << "CATEGORY MENU" << endl;
	cout << "0. Return to main menu" << endl;;
	cout << "1. Add category" << endl;
	cout << "CATEGORIES: " << endl;
	for (int i = 0; i < Categories.size(); i++)//Display all categories
	{
		cout << to_string(i + 2) + ". " + Categories[i].getName() << endl;
	}
	cout << "Choose Category to edit: " << endl;
	cin >> choice;
	while ((choice < 0) || (choice > (Categories.size() + 1)))//input validation
	{
		cin >> choice;
	}
	catInd = (choice - 2);//assign index of assignment to open based on user input
	switch (choice)
	{
	case 0: //RETURN TO MAIN MENU

		mainMenu();
		break;

	case 1: //ADD CATEGORY
		c = g.addCategory(c);
		Categories.push_back(c);
		catMenu();
		break;

	default: //OPEN CORRESPONDING ASSIGNMENT MENU
		assignMenu();
	}
}

void GradePredictor::assignMenu()
{
	Assignment a;
	system("CLS");//Display information about the category
	cout << "ASSIGNMENT MENU" << endl;
	cout << "Category: " << Categories[catInd].getName() << endl;
	cout << "Category weight: " << Categories[catInd].getWeight() << endl;
	Category c = Categories[(catInd)];

	cout << "0. Return to categories menu" << endl;//Display assignment options
	cout << "1. Edit category weight" << endl; 
	cout << "2. Add assignment" << endl;
	cout << "ASSIGNMENTS: " << endl;
	for (int i = 0; i < c.Assignments.size(); i++)//Display all existing assignments
	{
		cout << to_string(i + 3) + ". " + c.Assignments[i].getNameA() << endl;
	}
	cout << "Choose assignment to edit: " << endl;
	cin >> choice;
	if (c.Assignments.size() == 0)//cannot edit nonexistent assignments
	{
		while ((choice < 0) || (choice > 2))
		{
			cin >> choice;
		}
	}
	else
	{
		while ((choice < 0) || (choice > c.Assignments.size() - 1))//input validation
		{
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 0: //RETURN TO PREV MENU

		catMenu();
		break;

	case 1://EDIT CATEGORY WEIGHT
		double temp;
		system("CLS");
		cout << "Enter category weight (percent as decimal value): " << endl;
		cin >> temp;
		Categories[catInd].setWeight(temp);
		assignMenu();
		break;

	case 2: //ADD ASSIGNMENT
		
		a = Categories[catInd].newInfo(a);
		Categories[catInd].Assignments.push_back(a);
		assignMenu();
		break;


	default: //EDIT EXISTING ASSIGNMENT

		Categories[catInd].Assignments[(choice - 3)] = c.editAssignment(c.Assignments[(choice - 3)]);
		assignMenu();
	}
}





