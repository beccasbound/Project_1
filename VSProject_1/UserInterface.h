#pragma once
#include<iostream>
#include "Date.h"
#include "StringTokenizer.h"
#include "Assignment_Book.h"
#include"Assignment.h"
#include <string>

using namespace std;

class UserInterface
{
public:
	// constructor
	UserInterface(Assignment_Book assignments_from_file) { my_assignments = assignments_from_file; saved=true; }
	//main function to display menu options
	void main()
	{
		char input;
		Date temp_date;
		cout << "==================================MAIN MENU===================================" << endl 
			<< "Enter A to add an assignment: " << endl
			<< "Enter F to find for an assigment: " << endl
			<< "Enter D to display list of assignments: " << endl
			<< "Enter E to edit assignment: " << endl
			<< "Enter C to complete assignment: " << endl
			<< "Enter L to view the number of late assignments" << endl
			<< "Enter S to save changes to assignment book: " << endl
			<< "Enter Q to quit: " << endl << endl;
		cin >> input;
		input = toupper(input);   // the toupper function ensured that input of non capital letters will still work

		// novegate through the menu options
		switch (input) {
		case 'A':
			// add assignment to the list of assignments
			cin.ignore();
			cout << endl << "Enter assignment description: ";
			getline(cin, temp_description);
			cout << "Enter assigned date: (month/day/year)" << endl;
			cin >> temp_date;
			cout << "Enter due date: (month/day/year)" << endl;
			cin >> date;
			the_assignment.set_assigned_date(temp_date);
			the_assignment.set_due_date(date);
			the_assignment.set_description(temp_description);
			my_assignments.add_assignment(the_assignment);
			cout << "Assignment added." << endl;
			saved = false;
			mainOrQuit();
			break;

		case 'F':
			// find an assignemnt from assignment lists
			saved = false;
			cout << "Enter assigned date: (month/day/year)" << endl;
			cin >> date;
			cout << *(my_assignments.find_assignment(date)) << endl;
			cout<< "Would you like to edit this assignment? Y/N" << endl;
			cin >> input;
			input = toupper(input);
			// ask user if he/she wants to edit found assignment
			switch (input) {
			case 'Y':
				my_assignments.edit_assignment(date);
				break;
			case 'N':
				mainOrQuit();
				break;
			default:
				cout << "Invalid input" << endl;
				}
			mainOrQuit();
			break;

		case'D':
			// display all assignments
			my_assignments.display_all();
			mainOrQuit();
			break;

		case 'E':
			// edit assignment
			saved = false;
			cout << "Enter assigned date of assignment you would like to edit: (month/day/year)" << endl;
			cin >> temp_date;
			my_assignments.edit_assignment(temp_date);
			mainOrQuit();
			break;

		case'C':
			//complete assignment (submit assignment)
			saved = false;
			cout << "Enter assigned date of assignment you would like to complete: " << endl;
			cin >> temp_date;
			if (!temp_date.check_valid())
			{
				cout << endl << "Invalid date entered, please try again: " << endl;
				mainOrQuit();
			}
			cout << "Enter date of completion (month / day / year)" << endl;
			cin >> date;
			if (!date.check_valid())
			{
				cout << endl << "Invalid date entered, please try again: " << endl;
				mainOrQuit();
			}

			my_assignments.complete_assignment(temp_date, date);
			mainOrQuit();
			break;

		case'L':
			// display late assignment count
			cout << my_assignments.assignments_late_count()
				 << " Late assignments" << endl;
			mainOrQuit();
			break;
		case'S':
			// save any changes that have been made to assignments list and output it into the text file
			my_assignments.save("tester.txt");
			cout << "Save completed.";
			saved = true;
			mainOrQuit();
			break;

		case'Q':
			// quit
			if (saved == false) {
				ask_save();
			}
			break;

		default:
			cout << "Invalid input. Please try again" << endl;
			main();
		}
	}

	// this is a function that return the user to the main menu or allows user to quit.
	void mainOrQuit() { 
		char input;
		cout << endl << "Enter M to return to the main menu or Q to quit" << endl;
		cin >> input;
		input = toupper(input);

		switch (input) {
		case 'M':
			main();
			break;
		case 'Q':
			if (saved == false) {
				ask_save();
			}
			break;
		default:
			cout << "Invalid input. Please try again" << endl;
			mainOrQuit();
		}
	}
// prompt user to save changes
	void ask_save(){
		cout << "Would you like to save your changes? (Y/N)";
		cin >> input;
		input = toupper(input);
	switch (input) {
	case 'Y':
		my_assignments.save("tester.txt");
		cout << "Save completed.";
		saved = true;
		mainOrQuit();
		break;
	case 'N':
		break;
	default:
		cout << "Invalid input" << endl;
		ask_save();
	}
}
private:
	// decalre variable for user interface class
	Assignment_Book my_assignments;
	Date date;
	Assignment the_assignment;
	bool saved;
	char input;
	string temp_description;
};

