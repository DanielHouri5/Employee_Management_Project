//
// Created by hdani on 25/05/2023.
//

#ifndef SEMESTERB_TASK4_EX3_CUSTOMER_H
#define SEMESTERB_TASK4_EX3_CUSTOMER_H
#include "Person.h"

class Customer : virtual public Person
{
    public:
        // Constructor for the Customer class.
        explicit Customer(const double* paylist = nullptr, const int& size = 0, const char* name = nullptr, const long& id = 0);
        // Copy constructor for the Customer class.
        Customer(const Customer& other);
        // Virtual function representing the customer buying something.
        virtual void buy(double& pay);
        // Destructor for the Customer class.
        virtual ~Customer();
        // Virtual function that prints the details of the customer.
        virtual void print(ostream& output)const;
    private:
        // Pointer to an array of payment amounts.
        // Represents the list of payments made by the customer
        double* m_paylist;
        // Size of the payment array.
        int m_size;
};


#endif //SEMESTERB_TASK4_EX3_CUSTOMER_H
