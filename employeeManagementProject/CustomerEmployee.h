//
// Created by hdani on 25/05/2023.
//

#ifndef SEMESTERB_TASK4_EX3_CUSTOMEREMPLOYEE_H
#define SEMESTERB_TASK4_EX3_CUSTOMEREMPLOYEE_H
#include "Employee.h"
#include "Customer.h"

class CustomerEmployee : public Employee, public Customer
{
    public:
        // Constructor for the CustomerEmployee class.
        explicit CustomerEmployee(const double* paylist = nullptr, const int& size = 0, const double& salary = 0, const char* name = nullptr, const long& id = 0);
        // Copy constructor for the CustomerEmployee class.
        CustomerEmployee(const CustomerEmployee& other);
        // Overrides the buy() function from the Customer class.
        virtual void buy(double& pay);
        // Overrides the print() function from the Person class.
        virtual void print(ostream& output)const;
};


#endif //SEMESTERB_TASK4_EX3_CUSTOMEREMPLOYEE_H
