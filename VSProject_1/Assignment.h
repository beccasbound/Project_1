#ifndef ASSIGNMENT_H
#define ASSIGMENT_H
#include"Date.h"
#include <string>
#include <iostream>

#include"StringTokenizer.h"

using namespace std;

enum status {
	assigned,
	completed,
	late
};
/** Construct a new Assignment
@param due_date
@param description
@param assigned_date
@param assignment_satus
*/
class Assignment
{
private:
	Date due_date;
	string description;
	Date assigned_date;
	status assignment_status;
public:
	Assignment(const Date& the_due_date, const string& the_description,
		const Date& the_assigned_date, const status& the_status);

	// Default assignment
	Assignment();

	// Getters
	Date get_due_date() const;
	string get_description()const;
	Date get_assigned_date()const;
	status get_status() const;

	//setters
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
