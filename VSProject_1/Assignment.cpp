#include"Assignment.h"
#include <type_traits>

// functions to help read in enum type 
template<typename Enum>
class EnumReader
{
	Enum& e_;

	friend std::istream& operator >> (std::istream& in, const EnumReader& val) {
		typename std::underlying_type<Enum>::type asInt;
		if (in >> asInt) val.e_ = static_cast<Enum>(asInt);
		return in;
	}
public:
	EnumReader(Enum& e) : e_(e) {}
};

template<typename Enum>
EnumReader<Enum> read_enum(Enum& e)
{
	return EnumReader<Enum>(e);
}

Assignment::Assignment(const Date& the_due_date, const string& the_description,
	const Date& the_assigned_date, const status& the_status) : due_date(the_due_date),
	description(the_description), assigned_date(the_assigned_date), assignment_status(the_status) {}

// Default constructor for assignment class
Assignment::Assignment() : due_date(""), description(""), assigned_date(""), assignment_status(assigned) {}

// Getters
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
//setters
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

// still working one those
ostream& operator << (ostream& out, const Assignment& item)
{

	out << item.due_date.toString() << ", " << item.description << ", " << item.assigned_date.toString() << ", " << item.assignment_status << endl;;
	return out;
}

// still working one those will make couple changes to make them work correctly
istream& operator >> (istream& in, Assignment& item)
{

	if (in.good())
	{
		string data;

		while (getline(in, data))

		{
			string temp_status;
			String_Tokenizer st(data, ",");
			item.due_date = st.next_token();
			item.description = st.next_token();
			item.assigned_date = st.next_token();
			temp_status = st.next_token();
			if (temp_status == " assigned")
			{
				item.assignment_status = assigned;
			}
			else if (temp_status == " completed")
			{
				item.assignment_status = completed;
			}
			else if (temp_status == " late")
			{
				item.assignment_status = late;
			}
			in >> item.due_date >> item.description >> item.assigned_date >> read_enum(item.assignment_status);
		}
	}

	return in;
}

//overloaded less than operator
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
//overloaded > operator
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

// overloading = operator, we might make some changes if needed.
bool Assignment::operator==(const Assignment& rhs)
{
	return assigned_date == rhs.assigned_date && description == rhs.description && due_date == rhs.due_date &&
		assignment_status == rhs.assignment_status;
}



