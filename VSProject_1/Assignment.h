#ifndef ASSIGNMENT_H
#define ASSIGMENT_H
#include <string>

using namespace std;
//Class to represent an assigment
class Assignment
{
private:
    string due_date;
    string description;
    string assigned_date;
    string status;
public:
    Assignment(const string& the_due_date, const string& the_description,
        const string& the_assigned_date, const string& the_status) : due_date(the_due_date),
        description(the_description), assigned_date(the_assigned_date), status(the_status) {}

    // Default assignment
    Assignment() :due_date(""), description(""), assigned_date(""), status(""){}

    // Getters
    string get_due_date() const
    {
        return due_date;
    }
    string get_description()const
    {
        return description;
    }
    string get_assigned_date()const
    {
        return assigned_date;
    }
    string get_status()const
    {
        return status;
    }
    //setters
    void set_due_date(const string& new_due_date)
    {
        due_date = new_due_date;
    }
    void set_description(const string& new_description)
    {
        description=new_description;
    }
    void set_assigned_date(const string& new_assigned_date)
    {
        assigned_date = new_assigned_date;
    }
    void set_status(const string& new_status)
    {
        status = new_status;
    }
};


#endif
