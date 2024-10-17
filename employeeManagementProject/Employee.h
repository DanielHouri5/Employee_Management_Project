//
// Created by hdani on 25/05/2023.
//

#ifndef SEMESTERB_TASK4_EX3_EMPLOYEE_H
#define SEMESTERB_TASK4_EX3_EMPLOYEE_H
#include "Person.h"

class Employee : virtual public Person
{
    public:
        // Constructor with default values for salary, name, and id
        explicit Employee(const double& salary = 0, const char* name = nullptr, const long& id = 0);
        // Copy constructor
        Employee(const Employee& other);
        // Print function to display employee details
        virtual void print(ostream& output)const;
        // Getter function for salary
        double getSalary()const{return m_salary;}
        // Setter function for salary
        void setSalary(double salary);
    private:
        double m_salary;// Salary of the employee
};


#endif //SEMESTERB_TASK4_EX3_EMPLOYEE_H
