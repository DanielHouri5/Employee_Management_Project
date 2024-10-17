//
// Created by hdani on 25/05/2023.
//

#ifndef SEMESTERB_TASK4_EX3_PERSON_H
#define SEMESTERB_TASK4_EX3_PERSON_H
#include <iostream>

using namespace std;
class Person
{
    public:
        // Constructor with default arguments
        explicit Person(const char* name = nullptr, const long& id = 0);
        // Copy constructor
        Person(const Person& other);
        // Pure virtual destructor
        virtual ~Person() = 0;
        // Getter function for the id member variable
        long getId()const{return m_id;}
        // Virtual function to print the Person's information
        virtual void print(ostream& output)const;
        // Overloading the << operator to print the Person's information
        friend ostream& operator<<(ostream& output, const Person& thisPerson);
    private:
        char* m_name;// Pointer to hold the Person's name
        long m_id;// The Person's ID
};


#endif //SEMESTERB_TASK4_EX3_PERSON_H
