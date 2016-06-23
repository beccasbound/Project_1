 #include"Assignment.h"
#include <type_traits>

Assignment::Assignment(const Date& the_due_date, const string& the_description,
	const Date& the_assigned_date, const status& the_status) : due_date(the_due_date),
	description(the_description), assigned_date(the_assigned_date), assignment_status(the_status) {}

// Default constructor for assignment class
Assignment::Assignment() : due_date(""), description(""), assigned_date(""), assignment_status(assigned) {}


// Getters for the due date, description, assigned date and status
Date Assignment::get_due_date() const
{
	return due_date;
}
string Assignment::get_description()const
{
	return description;
}
Date Assignment::get_assigned_date()const
{
	return assigned_date;
}
status Assignment::get_status() const
{
	return assignment_status;
}

//setters for the due date, description, assigned date and status
void Assignment::set_due_date(const Date& new_due_date)
{
	due_date = new_due_date;
}
void Assignment::set_description(const string& new_description)
{
	description = new_description;
}
void Assignment::set_assigned_date(const Date& new_assigned_date)
{
	assigned_date = new_assigned_date;
}
void Assignment::set_status(const status& new_status)
{
	assignment_status = new_status;
}


// overloaded <<(output) operator which will allow to output data in to the file
ostream& operator << (ostream& out, const Assignment& item)
{
	string temp_assignment_status;
	temp_assignment_status=ToString(item.assignment_status);
	out << item.due_date.toString() << ", " << item.description << ", " << item.assigned_date.toString() << ", " << temp_assignment_status << endl;
	return out;
}

// overloaded >>(input) operator which will allow to read in data
istream& operator >> (istream& in, Assignment& item)
{
	Date h;
	string data;
	if (in.good())
	{
        getline(in, data);
		
			// string tokenizer function to devide data by comma
			String_Tokenizer st(data, ",");
			if (st.has_more_tokens())
			{
				string temp_status;
				item.due_date = Date(st.next_token(),US);
				item.description = st.next_token();
				item.description.erase(remove_if(item.description.begin(), item.description.end(), isspace), item.description.end());
				item.assigned_date = Date(st.next_token());
				temp_status = st.next_token();
				temp_status.erase(remove_if(temp_status.begin(), temp_status.end(), isspace), temp_status.end());
				if (temp_status == "assigned")
				{
					item.assignment_status = assigned;
				}
				else if (temp_status == "completed")
				{
					item.assignment_status = completed;
				}
				else if (temp_status == "late")
				{
					item.assignment_status = late;
				}
			}
		}
	
	return in;
}

//overloaded less than operator to compare assigned date
bool Assignment::operator< (const Assignment& rhs)
{
	if (assigned_date < rhs.assigned_date)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//overloaded > operator to compare assigned date
bool Assignment::operator> (const Assignment& rhs)
{
	if (assigned_date > rhs.assigned_date)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// overloading == operator to check if assignments are identical
bool Assignment::operator==(const Assignment& rhs)
{
	return assigned_date == rhs.assigned_date && description == rhs.description && due_date == rhs.due_date &&
		assignment_status == rhs.assignment_status;
}

