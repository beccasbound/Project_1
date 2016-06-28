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
            add_assignment(assignment); ///////////////////////////////////////////////
            assignment_count++;
        }
        else if (assignment.get_status() == 1 || assignment.get_status() == 2)/////////////////////////////////////////////////
            add_completed_assignment(assignment); 
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
    if (assigned_list.size() > 0 && completed_list.size() > 0) {
        cout << "Assignments not yet completed: ";
        if (assigned_list.size() > 0) {
            cout << endl;
            for (iter = assigned_list.begin(); iter != assigned_list.end(); iter++)
                cout << *iter;
        }
        else
            cout << "None" << endl;
        cout << "Completed assignments, including late submissions: ";
        if (completed_list.size() > 0) {
            cout << endl;
            for (iter = completed_list.begin(); iter != completed_list.end(); iter++)
                cout << *iter;
        }
        else
            cout << "None" << endl;
    }
    else
        cout << "No assignments to display." << endl;
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
<<<<<<< HEAD
   // cout << "There is no assignment with that assigned date in the assignment book." << endl;  
    found = false;
    return completed_list.end();
=======
   // cout << "There is no assignment with that assigned date in the assignment book." << endl;
	found = false;
	return completed_list.end();
		
>>>>>>> b01a7e26891818ebb426823b4ea1a1c84290420d
}

/*Assignment Assignment_Book::iter_to_assignment(list<Assignment>::iterator iter) {
    return *iter;
}*/

void Assignment_Book::display_assign(list<Assignment>::iterator iter) {
    cout << *iter;
}


/* Adds an assignment to assigned_list. Inserts in order of due date. */
void Assignment_Book::add_assignment(Assignment newAssignment) {

    if (assigned_list.empty())
        assigned_list.push_front(newAssignment);

    list<Assignment>::iterator iter = assigned_list.begin();

   

    while (iter != assigned_list.end() && *iter < newAssignment)
        ++iter; //iter points to the first assignment >= newAssignment
               //or the end
    assigned_list.insert(iter, newAssignment);
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

    list<Assignment>::iterator iter;

    for (iter = assigned_list.begin(); iter != assigned_list.end(); ++iter) {
        if (iter->get_assigned_date() == userEntered_assigned_date) { // assigned_date and due_date must be dates
            if (userEntered_completion_date > iter->get_due_date())
                iter->set_status(late); /////////////////////////////////////////////////////////////////////////
            add_completed_assignment(*iter);
            assigned_list.erase(iter);
            return;
        }
    }
    cout << "No assignment with that assigned date was found." << endl;
    return;
}

/* Iterates through assigned_list and completed_list, outputting info
for each assignment to the text file originally read from. When complete,
the contents of the file represent all user changes since most recent load. */
void Assignment_Book::save(string filename) {

}





