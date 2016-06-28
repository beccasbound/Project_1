#pragma once
#include<iostream>
#include "Date.h"
#include "Assignment.h"
#include "StringTokenizer.h"
#include "Assignment_Book.h"
#include"Assignment.h"
#include <string>

using namespace std;

class UserInterface
{
public:
    UserInterface(Assignment_Book assignments_from_file) { my_assignments = assignments_from_file; }

	// This is just the first draft and I know we are gonna make a lot of changes to this but we had to start somwhere.
	void main()
    {
		char input;
		Date temp_date;
		cout << "==================================MAIN MENU===================================" << endl // We dont have to use this exact wording. 
			<< "Enter A to add an assignment: " << endl
			<< "Enter S to search for an assigment: " << endl
<<<<<<< HEAD
			//<< "Enter C to display list of completed assignments: " << endl
=======
>>>>>>> b01a7e26891818ebb426823b4ea1a1c84290420d
			<< "Enter D to display list of assignments: " << endl
			<< "Enter E to edit assignment: " << endl
			<< "Enter C to complete assignment: " << endl
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
<<<<<<< HEAD
			cout << "Please enter assigned date--> " << endl;
            cin >> temp_date;
            search(temp_date);
			mainOrQuit();
			break;
		/*case 'C':
			cout << "Display complete" << endl;
			mainOrQuit();
			break;*/
		case'D':
			cout << "Display complete" << endl;
            display_list_of_assignments();
=======
			cout << "Enter assigned date:" << endl;
			
			cin >> date;
			search(date);
			mainOrQuit();
			break;

		case'D':

			display_list_of_assignments();
>>>>>>> b01a7e26891818ebb426823b4ea1a1c84290420d
			mainOrQuit();
            
			break;

		case 'E':
				
			cout << "Enter assigned date of assignment you would like to edit: " << endl;
			cin >> temp_date;

			edit(temp_date);
			

			mainOrQuit();
			break;

		case'C':

			cout << "Enter assigned date of assignment you would like to complete: " << endl;
			cin >> temp_date;
			complete(temp_date);
			mainOrQuit();
			break;


		case'Q':
			break;

		default:
			cout << "Invalid input. Please try again" << endl;
			main();
		}
	}



    void display_list_of_assignments() {
        my_assignments.display_all();
    }
    
   void search(Date date) {
       my_assignments.SetFound(true);
        list<Assignment>::iterator iter = my_assignments.find_assignment(date);
        if (my_assignments.GetFound() == false) {
            cout << "Date not found." << endl;
            return;
        }      
        cout << *iter;

        Assignment found_assignment = *iter;
    
       // my_assignments.display_assign(iter);

       // Assignment requested_assignment = my_assignments.iter_to_assignment(iter);

       // cout << requested_assignment;
   
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
	void add() { 
	
		// do error checking
		string description;
        Date assigned_date, due_date;
        Assignment new_assignment;
		

		cin.ignore();
		cout << "Enter assignment description: ";
		getline(cin, description);
        cout << "Enter assigned date: (month/day/year)" << endl;
        cin >> assigned_date;
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
        cout << "Due date : " << due_date.toString();

        new_assignment.set_assigned_date(assigned_date);
        new_assignment.set_description(description);
        new_assignment.set_due_date(due_date);
        new_assignment.set_status(assigned);

        my_assignments.add_assignment(new_assignment);

        cout << endl << "Assignment added" << endl;
<<<<<<< HEAD
        cout << new_assignment << endl << endl;
        my_assignments.display_all();
=======
		
        cout << new_assignment;
		

	}
	void display_list_of_assignments()
	{
		my_assignments.display_all();
	}

	void search (Date the_date)
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
			search( the_date);
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
		cout << "Changes made"<< endl << *iter << endl;
	}


	
>>>>>>> b01a7e26891818ebb426823b4ea1a1c84290420d

	void complete(Date the_date)
	{
		char input;
		my_assignments.SetFound(true);
		list<Assignment>::iterator iter = my_assignments.find_assignment(the_date);
		if (my_assignments.GetFound() == false) {
			cout << "Assignment not found" << endl;
			return;
		}

		Assignment found_assignment = *iter;

		cout << *iter << endl
			<< "Was the assignment completed on time? Y/N" << endl;
		cin >> input;

		input = toupper(input);
		switch (input) {
		case 'Y':
			found_assignment.set_status(completed);
			break;
		case 'N':
			found_assignment.set_status(late);
			break;
		default:
			cout << "Invalid input" << endl;
			complete(the_date);
		}
		*iter = found_assignment;
		cout << *iter << endl;
	}
	

	void save()
	{
		
	}

	
    private:
        Assignment_Book my_assignments;
<<<<<<< HEAD
        Date temp_date;
=======
		Date date;
		Assignment the_assignment;
>>>>>>> b01a7e26891818ebb426823b4ea1a1c84290420d
};

