/* This is the header file Assignment_Book.h. This is the interface for the
class Assignment_Book. Values of this type contain two lists: assigned_list and
completed_list. Using member functions, assignments represented in a text file
by lines in this format: date_assigned description date_due status, can be 
read and processed, each assignment being added to one of the two lists,
depending on status. Assignments can also be found, displayed, added, removed,
or completed. The assignment book can be saved, which writes the contents of 
both lists to the text file.
*/

#ifndef ASSIGNMENT_BOOK_H
#define ASSIGNMENT_BOOK_H

//#include "Ordered_list.h"
#include "Assignment.h"
#include "Date.h"
#include <list>
#include <string>

using namespace std;

class Assignment_Book {

private:

    /* Two lists - to hold current and completed assignments. */
    list<Assignment> assigned_list, completed_list;
    string source_file;
    bool modified;
    int late_count;
	bool found;

public:

    Assignment_Book() { late_count = 0; modified = false; }

    /* getters/setters for modified, late_count */
    bool isModified() { return modified; }
    int GetLate_Count() { return late_count; }
	bool GetFound() { return found; }
    void Modify() { modified = true; }
    void SetLate_Count(int num_lates) { late_count = num_lates; }
	void SetFound(bool val) { found = val; }

    /* Opens filename for reading, reads in each line by calling the overloaded
    << operator for the Assignment class. Populates the assigned_list and
    completed_list with assignments from filename. */
    void load(string filename);

    /* Displays all assignments in assigned_list followed by all assignments
    in completed list. */
    void display_all();

    /* Locates and returns reference (iterator) to assignment with indicated
    assigned date. Notifies user and returns without making changes if no
    assignment with indicated assigned date exists in assignment book. */
    list<Assignment>::iterator find_assignment(Date userEntered_assigned_date);

    /* Adds an assignment to assigned_list. Inserts in order of assigned date. */
    void add_assignment(Assignment newAssignment);

    /* Adds an assignment to completed_list. Inserts in order of assigned date. */
    void add_completed_assignment(Assignment newAssignment);

    /* Marks status of assignment as complete, places a copy of assignment
    in completed_assignments, then deletes it from assigned_list. */
    void complete_assignment(Date userEntered_assigned_date, Date userEntered_completion_date);

    /* Removes assignment from list. Deletes associated dynamic data. */
    void remove_assignment(Assignment to_delete);

    /* Iterates through assigned_list and completed_list, outputting info
    for each assignment to the text file originally read from. When complete,
    the contents of the file represent all user changes since most recent load. */
    void save(string filename);

};

#endif


