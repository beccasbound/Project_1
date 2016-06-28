#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include"Date.h"
#include <string>
#include <iostream>
#include<algorithm>
#include"StringTokenizer.h"

using namespace std;

/* Create a status - an enum type that tells us whether the assignment is assigned, completed, or late */
enum status {
	assigned,
	completed,
	late
};

//Function to convert enum type variable in to the string. It accepts enum type an return string
inline const char* ToString(status status_type)
{
	switch (status_type)
	{
	case assigned: return "assigned";
	case completed: return "completed";
	case late: return "late";
	}
}

/** Construct a new Assignment
@param due_date
@param description
@param assigned_date
@param assignment_satus
*/
class Assignment
{
private:
	// Initializing variables 
	// Due date of the assignment
	Date due_date;
	// Description of the assignment
	string description;
	// Assignbed date of the assignment
	Date assigned_date;
	// Status of the assignment
	status assignment_status;
public:
	//Member functions
	// Construct an empty Assignments
	Assignment();

	//Make copy of each variable
	Assignment(const Date& the_due_date, const string& the_description,
		const Date& the_assigned_date, const status& the_status);
	
	// Getters for the due date, description, assigned date and status
	Date get_due_date() const;
	string get_description()const;
	Date get_assigned_date()const;
	status get_status() const;

	//setters for the due date, description, assigned date and status
	void set_due_date(const Date& new_due_date);
	void set_description(const string& new_description);
	void set_assigned_date(const Date& new_assigned_date);
	void set_status(const status& new_status);
	

	//overlodaing<< opertaror to output the data to the the file
	friend ostream& operator <<(ostream& out, const Assignment& item);
	//overlodaing>> opertaror to read in the data from the file
	friend istream& operator >> (istream& in, Assignment& item);

	//overloaded <,>,== operator
	bool operator< (const Assignment& rhs);
	bool operator> (const Assignment& rhs);
	bool operator==(const Assignment& rhs);
	
};



#endif
