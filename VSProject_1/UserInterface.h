#pragma once
#include<iostream>
#include "Date.h"
#include "Assignment.h"
#include "StringTokenizer.h"
#include "Assignment_Book.h"
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
		cout << "==================================MAIN MENU===================================" << endl // We dont have to use this exact wording. 
			<< "Enter A to add an assignment: " << endl
			<< "Enter S to search for an assigment: " << endl
			//<< "Enter C to display list of completed assignments: " << endl
			<< "Enter D to display list of assignments: " << endl
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
	void add() { // this is the function I had trouble with we can change the way the user inputs the date after we figure out parseDate.
		//string assignmentName;
		string description;
		string currentString = "02/02/2016";
		//int month;
		//int day;
		//int year;
        Date assigned_date, due_date;
        Assignment new_assignment;

		cin.ignore();
		//cout << "Enter assignment name: ";
		//getline(cin, assignmentName);
		cout << "Enter assignment description: ";
		getline(cin, description);
        cout << "Enter assigned date: " << endl;

		/*	<< "Enter month: ";
		cin >> month;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter year: ";
		cin >> year;
		Date assignedDate(year, month, day, US);*/

        cin >> assigned_date;

		cout << "Assigned date : " << assigned_date.toString();
        cout << endl << "Enter due date: " << endl;
        /*<< "Enter month: ";
		cin >> month;
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter year: ";
		cin >> year;

		Date dueDate(year, month, day, US);*/

        cin >> due_date;

        cout << "Due date : " << due_date.toString();

        new_assignment.set_assigned_date(assigned_date);
        new_assignment.set_description(description);
        new_assignment.set_due_date(due_date);
        new_assignment.set_status(assigned);

        my_assignments.add_assignment(new_assignment);

        cout << endl << "Assignment added" << endl;
        cout << new_assignment << endl << endl;
        my_assignments.display_all();

	}

    private:
        Assignment_Book my_assignments;
        Date temp_date;
};

