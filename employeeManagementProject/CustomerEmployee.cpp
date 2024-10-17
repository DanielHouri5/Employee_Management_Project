//
// Created by hdani on 25/05/2023.
//

#include "CustomerEmployee.h"

// Constructor for the CustomerEmployee class.
// Initializes the paylist, size, salary, name, and id using the provided arguments.
CustomerEmployee::CustomerEmployee(const double *paylist, const int &size, const double &salary, const char *name,
                                   const long &id)
                                   : Person(name, id), Employee(salary, name, id), Customer(paylist, size, name, id)
                                   {
}

// Copy constructor for the CustomerEmployee class.
// Copies the paylist, size, salary, name, and id from the other CustomerEmployee object.
CustomerEmployee::CustomerEmployee(const CustomerEmployee &other)
: Person(other), Employee(other), Customer(other)
{
}

// Overrides the print() function from the Person class.
void CustomerEmployee::print(ostream &output) const
{
    // Calls the print() function of the Customer class to print the customer-specific details.
    Customer::print(output);
    // Prints the salary of the CustomerEmployee.
    output << "Salary: " << getSalary() << endl;
}

// Overrides the buy() function from the Customer class.
void CustomerEmployee::buy(double &pay)
{
    // Applies a 10% discount to the purchase amount.
    pay *= 0.9;
    // Calls the buy() function of the Customer class to update the paylist.
    Customer::buy(pay);
}
