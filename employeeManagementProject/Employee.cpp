//
// Created by hdani on 25/05/2023.
//

#include "Employee.h"

// Constructor with default values for salary, name, and id
Employee::Employee(const double &salary, const char *name, const long &id)
: Person(name, id)
{
    if (salary < 0)
        m_salary = salary*(-1);// Ensure the salary is positive
    else
        m_salary = salary;
}

// Copy constructor
Employee::Employee(const Employee &other)
: Person(other)
{
    if (other.m_salary < 0)
        m_salary = other.m_salary*(-1);// Ensure the salary is positive
    else
        m_salary = other.m_salary;
}

// Print function to display employee details
void Employee::setSalary(double salary)
{
    if (salary > 0 && salary >= m_salary/2 && salary <= m_salary*2)
        m_salary = salary;// Update the salary within the valid range
}

// Setter function for salary
void Employee::print(ostream &output) const
{
    Person::print(output);// Call the base class print function
    output << "Salary: " << m_salary << endl;// Print the employee's salary
}



