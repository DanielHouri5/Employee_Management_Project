//
// Created by hdani on 25/05/2023.
//
#include <cstring>
#include "Person.h"
#include "CustomerEmployee.h"
// Constructor with default arguments
Person::Person(const char *name, const long &id)
{
    if(name == nullptr)
        m_name = nullptr;
    else
    {
        // Allocate memory for the name and copy the input name
        m_name = new char[strlen(name)+1];
        strcpy(m_name, name);
    }
    int count = 0;
    long tempId = id;
    // Count the number of digits in the ID
    while (tempId != 0)
    {
        ++count;
        tempId /= 10;
    }
    // Check if the ID has 8 or 9 digits, otherwise set it to 0
    if(count == 8 || count == 9)
        m_id = id;
    else
        m_id = 0;
}

// Copy constructor
Person::Person(const Person &other)
{
    if(other.m_name == nullptr)
        m_name = nullptr;
    else
    {
        // Allocate memory for the name and copy the other person's name
        m_name = new char[strlen(other.m_name)+1];
        strcpy(m_name, other.m_name);
    }
    int count = 0;
    long tempId = other.m_id;
    // Count the number of digits in the ID
    while (tempId != 0)
    {
        tempId /= 10;
        ++count;
    }
    // Check if the ID has 8 or 9 digits, otherwise set it to 0
    if(count == 8 || count == 9)
        m_id = other.m_id;
    else
        m_id = 0;
}

// Pure virtual destructor
Person::~Person()
{
    delete[]m_name;// Deallocate the dynamically allocated memory for the name
}

// Virtual function to print the Person's information
void Person::print(ostream &output) const
{
    // Check if the dynamic type of the object is CustomerEmployee using typeid
    if (typeid(*this) == typeid(CustomerEmployee))
        output << "Type: " << typeid(*this).name()+2 << endl << "Name: " << m_name << endl << "Id: " << m_id << endl;
    else
        output << "Type: " << typeid(*this).name()+1 << endl << "Name: " << m_name << endl << "Id: " << m_id << endl;
}

// Overloading the << operator to print the Person's information
ostream &operator<<(ostream &output, const Person &thisPerson)
{
    // Call the print function of the Person object to output its details
    thisPerson.print(output);
    // Return the output stream
    return output;
}
