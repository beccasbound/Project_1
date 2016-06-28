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
	UserInterface(Assignment_Book assignments_from_file) { my_assignments = assignments_from_file; saved=true; }

	// This is just the first draft and I know we are gonna make a lot of changes to this but we had to start somwhere.
	void main()
	{
		char input;
		Date temp_date;
		cout << "==================================MAIN MENU===================================" << endl // We dont have to use this exact wording. 
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

		switch (input) {
		case 'A':
			
			


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
			saved = false;
			cout << "Enter assigned date: (month/day/year)" << endl;
			cin >> date;
			//my_assignments.SetFound(true);
			//list<Assignment>::iterator iter = ;
			/*if (my_assignments.GetFound() == false) {
			cout << "Assignment not found" << endl;
			return;
			}*/
			cout << *my_assignments.find_assignment(date) << endl << "Would you like to edit this assignment? Y/N" << endl;
			cin >> input;
			input = toupper(input);
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

			my_assignments.display_all();
			mainOrQuit();
			break;

		case 'E':
			saved = false;
			cout << "Enter assigned date of assignment you would like to edit: (month/day/year)" << endl;
			cin >> temp_date;

			my_assignments.edit_assignment(temp_date);


			mainOrQuit();
			break;

		case'C':

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


			cout << my_assignments.assignments_late_count()
				<< " Late assignments" << endl;
			mainOrQuit();
			break;
		case'S':


			my_assignments.save("tester.txt");
			cout << "Save completed.";
			saved = true;

			mainOrQuit();
			break;

		case'Q':
			if (saved == false) {
				ask_save();
			}
			
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
			if (saved == false) {
				ask_save();
			}
			break;
		default:
			cout << "Invalid input. Please try again" << endl;
			mainOrQuit();
		}
	}
/*	void add() {


		string description;
		Date assigned_date, due_date;
		Assignment new_assignment;


		cin.ignore();
		cout << endl << "Enter assignment description: ";
		getline(cin, description);
		cout << "Enter assigned date: (month/day/year)" << endl;
		cin >> assigned_date;

		my_assignments.SetFound(true);
		my_assignments.find_assignment(assigned_date);
		if (my_assignments.GetFound() == true) {
			cout << "Assignment with this date already exist.  Please try again " << endl;
			add();
		}
		if (!assigned_date.check_valid())
		{
			cout << endl << "Invalid date entered, please try again: " << endl;
			add();
		}
		cout << "Assigned date : " << assigned_date.toString();
		cout << endl << "Enter due date: (month/day/year)" << endl;
		cin >> due_date;
		if (!due_date.check_valid())
		{
			cout << endl << "Invalid date entered, please try again: " << endl;
			add();
		}


		if (assigned_date > due_date)
		{
			cout << "assigned date is after due date. Please try again " << endl;
			add();
		}
		cout << "Due date : " << due_date.toString();

		new_assignment.set_assigned_date(assigned_date);
		new_assignment.set_description(description);
		new_assignment.set_due_date(due_date);
		new_assignment.set_status(assigned);

		my_assignments.add_assignment(new_assignment);


		cout << "Assignment added" << endl;

		cout << new_assignment;


	}
	*/


	void ask_save(){
		cout << "Would you like to save your changes?";
		cin >> input;
		input = toupper(input);
	switch (input) {
	case 'Y':
		my_assignments.save("tester.txt");
		cout << "Save completed.";
		saved = true;
		break;
	case 'N':
		break;
	default:
		cout << "Invalid input" << endl;
		ask_save();
	}
		
	}
/*	void display_list_of_assignments()
	{
		my_assignments.display_all();
	}

	void search(Date the_date)
	{
		char input;
		my_assignments.SetFound(true);
		list<Assignment>::iterator iter = my_assignments.find_assignment(the_date);
		if (my_assignments.GetFound() == false) {
			cout << "Assignment not found" << endl;
			return;
		}

		cout << *iter << endl << "Would you like to edit this assignment? Y/N" << endl;
		cin >> input;
		input = toupper(input);
		switch (input) {
		case 'Y':
			edit(the_date);
			break;
		case 'N':
			mainOrQuit();
			break;
		default:
			cout << "Invalid input" << endl;
			search(the_date);
		}

	}
	void edit(Date the_date) {
		Date new_dueDate;
		string new_description;
		my_assignments.SetFound(true);
		list<Assignment>::iterator iter = my_assignments.find_assignment(the_date);
		if (my_assignments.GetFound() == false) {
			cout << "Assignment not found" << endl;
			return;
		}
		Assignment found_assignment = *iter;
		cout << *iter << endl;

		cout << "Enter new due date: ";
		cin >> new_dueDate;

		if (!new_dueDate.check_valid())
		{
			cout << endl << "Invalid date entered, please try again: " << endl;
			edit(the_date);
		}
		found_assignment.set_due_date(new_dueDate);
		cout << "Enter new description: ";
		cin >> new_description;
		found_assignment.set_description(new_description);
		*iter = found_assignment;
		cout << "Changes made" << endl << *iter << endl;
	}




	void complete(Date the_date)
	{



		Date completion_date;
		my_assignments.SetFound(true);
		list<Assignment>::iterator iter = my_assignments.find_assignment(the_date);
		if (my_assignments.GetFound() == false) {
			cout << "Assignment not found" << endl;
			return;
		}
		Assignment found_assignment = *iter;
		cout << "Enter date of completion (month / day / year)" << endl;
		cin >> completion_date;

		if (!completion_date.check_valid()) {
			cout << "Completion date is not valid. Please try again" << endl;
			complete(the_date);
		}
		if (completion_date < found_assignment.get_assigned_date()) {
			cout << "Completion date is before assigned date. Please try again" << endl;
			complete(the_date);
		}
		if (completion_date > found_assignment.get_due_date()) {
			found_assignment.set_status(late);
		}
		else {
			found_assignment.set_status(completed);
		}


		*iter = found_assignment;
		cout << *iter << endl;

		//my_assignments.complete_assignment()
		//complete_assignment(Date userEntered_assigned_date, Date userEntered_completion_date)
	}


	void save_or_revert() {
		char input;
		cout << "Would you like to save your changes? " << endl;
		cin >> input;
		input = toupper(input);
		switch (input) {
		case 'Y':
			edit(the_date);
			break;
		case 'N':
			mainOrQuit();
			break;
		default:
			cout << "Invalid input" << endl;
			search(the_date);

		}
	}*/

private:
	Assignment_Book my_assignments;
	Date date;
	Assignment the_assignment;
	bool saved;
	char input;
	string temp_description;
};

