//
// Created by hdani on 25/05/2023.
//

#include "Customer.h"


// Constructor for the Customer class.
Customer::Customer(const double *paylist, const int &size, const char *name, const long &id)
: Person(name, id)
{
    // Check if the size is 0 or the paylist is nullptr
    if (size == 0 || paylist == nullptr)
    {
        m_paylist = nullptr;
        m_size = 0;
    }
    else
    {
        // Allocate memory for the paylist and copy the values
        m_size = size;
        m_paylist = new double[m_size];
        for (int i = 0; i < m_size; ++i)
            m_paylist[i] = paylist[i];
    }
}

// Copy constructor for the Customer class.
Customer::Customer(const Customer &other)
: Person(other)
{
    // Check if the other object has no paylist or the paylist is nullptr
    if (other.m_size == 0 || other.m_paylist == nullptr)
    {
        m_paylist = nullptr;
        m_size = 0;
    }
    else
    {
        // Allocate memory for the paylist and copy the values
        m_size = other.m_size;
        for (int i = 0; i < m_size; ++i)
            m_paylist[i] = other.m_paylist[i];
    }
}

// Destructor for the Customer class.
Customer::~Customer()
{
    // Deallocate memory for the paylist
    delete[]m_paylist;
}

// Virtual function representing the customer buying something.
void Customer::buy(double &pay)
{
    double* tempPaylist;
    // Allocate memory for a new paylist with increased size
    tempPaylist = new double[m_size+1];
    // Copy the existing paylist to the new paylist
    for (int i = 0; i < m_size; ++i)
        tempPaylist[i] = m_paylist[i];
    // Add the new payment to the end of the paylist
    tempPaylist[m_size] = pay;
    ++m_size;
    // Deallocate memory for the old paylist
    delete[]m_paylist;
    // Update the paylist pointer to point to the new paylist
    m_paylist = tempPaylist;
}
// Virtual function that prints the details of the customer.
void Customer::print(ostream &output) const
{
    // Call the base class's print function
    Person::print(output);
    // Print the size of the paylist
    output << "Pay list size: " << m_size <<endl;
    // Print the paylist of the customer
    output << "The pay list of the customer:" << endl;
    output << "----------" << endl;
    for (int i = 0; i < m_size; ++i)
        output << i+1 << ") " << m_paylist[i] << endl;
    output << "----------" << endl;
}




