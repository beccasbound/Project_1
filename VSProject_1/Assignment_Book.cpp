#include "Assignment_Book.h"
#include <fstream>
#include <iostream>

/* opens filename for reading, reads in each line by calling the overloaded
<< operator for the assignment class. populates the assigned_list and
completed_list with assignments from filename. */
void Assignment_Book::load(string filename) {
    int assignment_count = 0;
    Assignment assignment;
    ifstream fin(filename);
    if (!fin)
        throw std::exception("Input file not opened!");
	while (fin >> assignment) {
		if (assignment.get_status() == 0) {
			add_assignment(assignment);
			assignment_count++;
		}
		else if (assignment.get_status() == 1 || assignment.get_status() == 2) {
			add_completed_assignment(assignment);
			assignment_count++;
		
	}
        else throw std::exception("Assignment has non-standard status code.");
    }
    if (assignment_count == 0)
        cout << "No assignments to load." << endl;
    return;
}

/* Displays all assignments in assigned_list followed by all assignments
in completed list. */
void Assignment_Book::display_all() {
    list<Assignment>::iterator iter;
    if (assigned_list.size() > 0 || completed_list.size() > 0) {
        cout << endl << "Assignments not yet completed: ";
        if (assigned_list.size() > 0) {
            cout << endl << "________________________________________________________________________" << endl
				<< " DUE DATE     ||       DESCRIPTION       ||  ASSIGNED DATE ||   STATUS||"<< endl
				<< "========================================================================" << endl;
            iter = assigned_list.begin();
            for (int i = 0; i < assigned_list.size(); i++) {
                cout << *iter;
                ++iter;
            }

        }
        else
            cout << "None" << endl;
        cout << endl << "Completed assignments, including late submissions: ";
        if (completed_list.size() > 0) {
			cout << endl << "________________________________________________________________________" << endl
				<< " DUE DATE     ||       DESCRIPTION       ||  ASSIGNED DATE ||   STATUS||" << endl
				<< "========================================================================" << endl;
            for (iter = completed_list.begin(); iter != completed_list.end(); iter++)
                cout << *iter;
        }
        else
            cout << "None" << endl;
    }
    else
        cout << "No assignments to display." << endl;
    cout << endl;
    return;
}

/* Locates and returns reference (iterator) to assignment with indicated
assigned date. Notifies user and returns assigned_list.end() if no
assignment with indicated assigned date exists in assignment book. */
list<Assignment>::iterator Assignment_Book::find_assignment(Date userEntered_assigned_date) {

    list<Assignment>::iterator iter;

    for (iter = assigned_list.begin(); iter != assigned_list.end(); ++iter) {
        if (iter->get_assigned_date() == userEntered_assigned_date) // assigned_date and due_date must be dates
            return iter;
    }
    for (iter = completed_list.begin(); iter != completed_list.end(); ++iter) {
        if (iter->get_assigned_date() == userEntered_assigned_date) // assigned_date and due_date must be dates
            return iter;
    }
     cout << "There is no assignment with that assigned date in the assignment book." << endl;  
    found = false;
    return completed_list.end();
     cout << "There is no assignment with that assigned date in the assignment book." << endl;
    found = false;
    return completed_list.end();
}


void Assignment_Book::display_assign(list<Assignment>::iterator iter) {
    cout << *iter;
}


/* Adds an assignment to assigned_list. Inserts in order of due date. */
void Assignment_Book::add_assignment(Assignment newAssignment) {

    if (assigned_list.empty())
        assigned_list.push_front(newAssignment);
    else {

        list<Assignment>::iterator iter = assigned_list.begin();

        while (iter != assigned_list.end() && *iter < newAssignment)
            ++iter; //iter points to the first assignment >= newAssignment
                    //or the end
        assigned_list.insert(iter, newAssignment);
    }
}

/* Adds an assignment to completed_list. Inserts in order of assigned date.
Intended to be used when loading assignments with status "complete" or "late"
from text file. */
void Assignment_Book::add_completed_assignment(Assignment newAssignment) {

    list<Assignment>::iterator iter = completed_list.begin();

    while (iter != completed_list.end() && *iter < newAssignment)
        ++iter; //iter points to the first assignment >= newAssignment
                //or the end
    completed_list.insert(iter, newAssignment);
}

/* Marks status of assignment as complete, places a copy of assignment
in completed_assignments, then deletes it from assigned_list. */
void Assignment_Book::complete_assignment(Date userEntered_assigned_date, Date userEntered_completion_date) {

    if (userEntered_assigned_date > userEntered_completion_date) {
        cout << "The completion date cannot be earlier than the assigned date." << endl;
        return;
    }
	
	SetFound(true);
	list<Assignment>::iterator iter = find_assignment(userEntered_assigned_date);
	if (GetFound() == false) {
		cout << "Assignment not found" << endl;
		return;
	}
            if (userEntered_completion_date > iter->get_due_date()){
                iter->set_status(late);
			}
            else{
                iter->set_status(completed);
}
            add_completed_assignment(*iter);
			cout << *iter << endl;
			assigned_list.remove(*iter);

            return;
        }

/* Iterates through assigned_list and completed_list, outputting info
for each assignment to the text file originally read from. When complete,
the contents of the file represent all user changes since most recent load. */
void Assignment_Book::save(string filename) {

    ofstream fout(filename);
    list<Assignment>::iterator iter;

    for (iter = assigned_list.begin(); iter != assigned_list.end(); ++iter)
        fout << *iter;

    for (iter = completed_list.begin(); iter != completed_list.end(); ++iter)
        fout << *iter;

}
int Assignment_Book::assignments_late_count()
{
	for (list<Assignment>::iterator iter = completed_list.begin(); iter != completed_list.end(); ++iter)
	{

		if (iter->get_status() == late)
		{
			++late_count;
		}
		
	}
return late_count;
}

void Assignment_Book::edit_assignment(Date the_date) {
	Date new_dueDate;
	string new_description;
	bool is_valid = false;

	list<Assignment>::iterator iter = find_assignment(the_date);
	
	Assignment found_assignment = *iter;
	cout << found_assignment << endl;

	while (is_valid==false) {
	cout << "Enter new due date: ";
	cin >> new_dueDate;
	if (new_dueDate.check_valid()) {
		is_valid = true;
	}
	else
		cout << "Invalid date. Please try again." << endl;
	}
	
	found_assignment.set_due_date(new_dueDate);
	cout << "Enter new description: ";
	cin.ignore();
	getline(cin, new_description);
	found_assignment.set_description(new_description);
	*iter = found_assignment;
	cout << "Changes made" << endl << *iter << endl;

}






