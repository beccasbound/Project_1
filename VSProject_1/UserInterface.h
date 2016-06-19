#pragma once
#include<iostream>
#include "Date.h"
#include "StringTokenizer.h"
#include <string>

using namespace std;

class UserInterface
{
public:
	// This is just the first draft and I know we are gonna make a lot of changes to this but we had to start somwhere.
	void main()
	{
		char input;
		cout << "==================================MAIN MENU===================================" << endl // We dont have to use this exact wording. 
			<< "Enter A to add an assignment: " << endl
			<< "Enter S to search for an assigment: " << endl
			<< "Enter C to display list of completed assignments: " << endl
			<< "Enter D to display list of uncompleted assignments: " << endl
			<< "Enter E to edit assignment: " << endl
			<< "Enter Q to quit: " << endl << endl;
		cin >> input;
		input = toupper(input);   // the toupper function ensured that input of non capital letters will still work

		switch (input) {
		case 'A':
			cout << "Assignment added" << endl;
			add();
			mainOrQuit();
			break;
		case 'S':
			cout << "Search completed" << endl;
			mainOrQuit();
			break;
		case 'C':
			cout << "Display complete" << endl;
			mainOrQuit();
			break;
		case'D':
			cout << "Display complete" << endl;
			mainOrQuit();
			break;
		case 'E':
			cout << "Edit complete" << endl;
			mainOrQuit();
			break;
		case'Q':
			break;
		default:
			cout << "Invalid input. Please try again" << endl;
			main();
		}
	}





	void mainOrQuit() { // this is a function that return the user to the main menu or allows them to quit.
		char input;
		cout << endl << "Enter M to return to the main menu or Q to quit" << endl;
		cin >> input;
		input = toupper(input);

		switch (input) {
		case 'M':
			main();
			break;
		case 'Q':
			break;
		default:
			cout << "Invalid input. Please try again" << endl;
			mainOrQuit();
		}
	}
	void add() { // this is the function I had trouble with we can change the way the user inputs the date after we figure out parseDate.
		string assignmentName;
		string description;
		string currentString = "02/02/2016";
		int month;
		int day;
		int year;

		cin.ignore();
		cout << "Enter assignment name: ";
		getline(cin, assignmentName);
		cout << "Enter assignment description: ";
		getline(cin, description);
		cout << "Enter assigned date: " << endl
			<< "Enter month: ";
		cin >> month;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter year: ";
		cin >> year;
		Date assignedDate(year, month, day, US);
		cout << "Assigned date : " << assignedDate.toString();
		cout << endl << "Enter due date: " << endl
			<< "Enter month: ";
		cin >> month;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter year: ";
		cin >> year;

		Date dueDate(year, month, day, US);
		cout << "Due date : " << assignedDate.toString()
			<< endl << "Assignment added";
	}
};

