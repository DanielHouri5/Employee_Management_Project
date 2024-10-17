#include <iostream>
#include <cstring>
#include "LinkedList.h"
// Constants
#define SIZE_OF_NUM_OF_TYPES 2
#define NUM_OF_EMPLOYEES 0
#define NUM_OF_CUSTOMERS 1
#define MAX_SIZE_OF_NAMES 21
#define ENTER '\n'
// Enums
typedef enum{ADD_PERSON_TO_LIST = 1, ADD_PAY_TO_PAY_LIST_OF_CUSTOMER, SET_SALARY_OF_EMPLOYEE, PRINT_AVERAGE_OF_SALARIES, PRINT_ALL_PERSONS, DELETE_LIST_AND_EXIT}options;
typedef enum{EMPLOYEE = 1, CUSTOMER, CUSTOMER_EMPLOYEE}persons;
// Function declarations
int& find_types(const LinkedList& personsList);
void addPerson(LinkedList& personsList);
void addPay(LinkedList& personsList);
void setSalary(LinkedList& personsList);
void printAverageOfSalaries(LinkedList& personsList);
void printPersons(LinkedList& personsList);
int main()
{
    LinkedList* personsList;// Pointer to a LinkedList object
    personsList = new LinkedList();// Create a new LinkedList object
    bool flag = true;// Flag variable for the main loop
    int option;// Variable to store the user's option
    while (flag)
    {
        // Print menu options
        cout << "Please choose one of the following options:" << endl
          << "1. Add Person to list." << endl
          << "2. Add a pay to the pay list of the customer." << endl
          << "3. Set the salary of the employee." << endl
          << "4. Print the salary's average of the employees." << endl
          << "5. Print all the persons." << endl
          << "6. Delete list and exit." << endl;
        cin >> option;// Read the user's option
        switch (option)
        {
            case ADD_PERSON_TO_LIST:
                addPerson(*personsList);// Call the addPerson function
                break;
            case ADD_PAY_TO_PAY_LIST_OF_CUSTOMER:
                addPay(*personsList);// Call the addPay function
                break;
            case SET_SALARY_OF_EMPLOYEE:
                setSalary(*personsList);// Call the setSalary function
                break;
            case PRINT_AVERAGE_OF_SALARIES:
                printAverageOfSalaries(*personsList);// Call the printAverageOfSalaries function
                break;
            case PRINT_ALL_PERSONS:
                printPersons(*personsList);// Call the printPersons function
                break;
            case DELETE_LIST_AND_EXIT:
                flag = false;// Set the flag to false for exit the loop
                break;
            default://When the user selects an option number that does not exist then he receives a reselection message.
                cout << "You choose an illegal option, please try again." << endl;
        }
    }
    return 0;
}

// Find and count the number of different types of persons in the list
int& find_types(LinkedList& personsList)
{
    int* numOfTypes = new int[SIZE_OF_NUM_OF_TYPES];// Create an array to store the counts of different types
    numOfTypes[NUM_OF_EMPLOYEES] = 0;// Initialize the count of employees
    numOfTypes[NUM_OF_CUSTOMERS] = 0;// Initialize the count of customers
    if (personsList.getListHead() != nullptr)
    {
        LinkedList tempList(personsList);// Create a temporary list to iterate over the persons
        while (tempList.getListHead() != nullptr)// Iterate over the temporary list
        {
            // Check the type of each person and update the counts accordingly
            if (typeid(*(tempList.getListHead())->getData()) == typeid(Employee)
            || typeid(*(tempList.getListHead())->getData()) == typeid(CustomerEmployee))
                ++numOfTypes[NUM_OF_EMPLOYEES];// Increment the count of employees
            if (typeid(*(tempList.getListHead())->getData()) == typeid(Customer)
                || typeid(*(tempList.getListHead())->getData()) == typeid(CustomerEmployee))
                ++numOfTypes[NUM_OF_CUSTOMERS];// Increment the count of customers
            tempList.setListHead(tempList.getListHead()->getNext());// Move to the next shape in the list
        }
    }
    return *numOfTypes;// Return the array of counts
}

void addPerson(LinkedList& personsList)
{
    int option;
    cout << "Please choose what shape you want to add:" << endl
         << "1. Employee." << endl
         << "2. Customer." << endl
         << "3. CustomerEmployee." << endl;
    cin >> option;// Read the user's choice
    if (option >= EMPLOYEE && option <= CUSTOMER_EMPLOYEE)
    {
        while (getchar() != ENTER);// Clear the input buffer
        char temp[MAX_SIZE_OF_NAMES];
        cout << "Please enter the name of the person:" << endl;
        cin.getline(temp, MAX_SIZE_OF_NAMES);// Read the name from input
        char *name = new char[strlen(temp) + 1];
        strcpy(name, temp);// Allocate memory and copy the name

        long id;
        cout << "Please enter the id of the person:" << endl;
        cin >> id;// Read the id from input
        double salary;
        if (option == EMPLOYEE || option == CUSTOMER_EMPLOYEE)
        {
            cout << "Please enter the salary of the employee:" << endl;
            cin >> salary;
            if (option == EMPLOYEE)
            {
                Employee* employee;
                employee = new Employee(salary, name, id);// Create a new Employee object
                personsList += *employee;// Add the Employee to the LinkedList
            }
        }
        if (option == CUSTOMER || option == CUSTOMER_EMPLOYEE)
        {
            int size;
            cout << "Please enter the num of pays of the customer:" << endl;
            cin >> size;// Read the number of pays from input
            double* paylist;
            paylist = new double[size];// Create a dynamic array to store pays
            for (int i = 0; i < size; ++i)
            {
                cout << "Please enter pay number " << i+1 << ":" << endl;
                cin >> paylist[i];// Read each pay from input
            }
            if (option == CUSTOMER)
            {
                Customer* customer;
                customer = new Customer(paylist, size, name, id);// Create a new Customer object
                personsList += *customer;// Add the Customer to the LinkedList
            }
            else
            {
                CustomerEmployee* customerEmployee;
                customerEmployee = new CustomerEmployee(paylist, size, salary, name, id);// Create a new CustomerEmployee object
                personsList += *customerEmployee;// Add the CustomerEmployee to the LinkedList
            }
        }
    }
}

void addPay(LinkedList& personsList)
{
    if (personsList.getListHead() != nullptr)
    {
        long id;
        cout << "Please enter the id of the customer:" << endl;
        cin >> id;// Read the customer's id from input
        long tempId = id;
        int count = 0;
        while (tempId != 0)
        {
            ++count;
            tempId /= 10;
        }
        if (count != 8 && count != 9)
            cout << "You entered an illegal id!" << endl;
        else
        {
            double pay;
            cout << "Please enter the pay that you want to add:" << endl;
            cin >> pay;// Read the pay amount from input
            if (pay <= 0)
                cout << "You entered an illegal pay!" << endl;
            else
            {
                LinkedList tempList(personsList);// Create a temporary list to iterate over the persons
                while (tempList.getListHead() != nullptr)// Iterate over the temporary list
                {
                    if (tempList.getListHead()->getData()->getId() == id)
                    {
                        // Check if the current node holds a Customer object
                        if (typeid(*(tempList.getListHead())->getData()) == typeid(Customer))
                        {
                            dynamic_cast<Customer*>(tempList.getListHead()->getData())->buy(pay);
                            tempList.setListHead(nullptr);
                            break;
                        }
                        // Check if the current node holds a CustomerEmployee object
                        if(typeid(*(tempList.getListHead())->getData()) == typeid(CustomerEmployee))
                        {
                            dynamic_cast<CustomerEmployee*>(tempList.getListHead()->getData())->buy(pay);
                            tempList.setListHead(nullptr);
                            break;
                        }
                    }
                    tempList.setListHead(tempList.getListHead()->getNext());// Move to the next shape in the list
                }
            }
        }
    }
    else
        cout << "The list is empty!" << endl;
}

void setSalary(LinkedList& personsList)
{
    if (personsList.getListHead() != nullptr)
    {
        long id;
        cout << "Please enter the id of the customer:" << endl;
        cin >> id;// Read the customer's id from input
        long tempId = id;
        int count = 0;
        while (tempId != 0)
        {
            ++count;
            tempId /= 10;
        }
        if (count != 8 && count != 9)
            cout << "You entered an illegal id!" << endl;
        else
        {
            double salary;
            cout << "Please enter the new salary:" << endl;
            cin >> salary;// Read the customer's salary from input
            if (salary <= 0)
                cout << "You entered an illegal salary!" << endl;
            else
            {
                LinkedList tempList(personsList);// Create a temporary list to iterate over the persons
                while (tempList.getListHead() != nullptr)// Iterate over the temporary list
                {
                    if (tempList.getListHead()->getData()->getId() == id)
                    {
                        // Check if the current node holds an Employee object
                        if (typeid(*(tempList.getListHead())->getData()) == typeid(Employee))
                        {
                            dynamic_cast<Employee*>(tempList.getListHead()->getData())->setSalary(salary);
                            tempList.setListHead(nullptr);
                            break;
                        }
                        // Check if the current node holds an CustomerEmployee object
                        if(typeid(*(tempList.getListHead())->getData()) == typeid(CustomerEmployee))
                        {
                            dynamic_cast<CustomerEmployee*>(tempList.getListHead()->getData())->setSalary(salary);
                            tempList.setListHead(nullptr);
                            break;
                        }
                    }
                    tempList.setListHead(tempList.getListHead()->getNext());// Move to the next shape in the list
                }
            }
        }
    }
    else
        // Print a message indicating that the list is empty
        cout << "The list is empty!" << endl;
}

void printAverageOfSalaries(LinkedList& personsList)
{
    // Check if the list is not empty
    if (personsList.getListHead() != nullptr)
    {
        int count = 0;// Initialize a counter for employees and customer employees
        double sum = 0;// Initialize a variable to store the sum of salaries
        LinkedList tempList(personsList);// Create a temporary list to iterate over the persons
        while (tempList.getListHead() != nullptr)// Iterate over the temporary list
        {
            // Check if the current node holds an Employee object
            if (typeid(*(tempList.getListHead())->getData()) == typeid(Employee))
            {
                // Add the salary of the Employee to the sum
                sum += dynamic_cast<Employee*>(tempList.getListHead()->getData())->getSalary();
                // Increment the count of employees
                ++count;
            }
            // Check if the current node holds an CustomerEmployee object
            if (typeid(*(tempList.getListHead())->getData()) == typeid(CustomerEmployee))
            {
                // Add the salary of the CustomerEmployee to the sum
                sum += dynamic_cast<CustomerEmployee*>(tempList.getListHead()->getData())->getSalary();
                // Increment the count of employees
                ++count;
            }
            tempList.setListHead(tempList.getListHead()->getNext());// Move to the next shape in the list
        }
        cout << "The salary's average of the employees is " << sum/count << "." << endl;
    }
    else
        // Print a message indicating that the list is empty
        cout << "The list is empty!" << endl;
}

void printPersons(LinkedList& personsList)
{
    // Check if the list is not empty
    if (personsList.getListHead() != nullptr)
        // Print the contents of the list
        cout << personsList << endl;
    else
        // Print a message indicating that the list is empty
        cout << "The list is empty!" << endl;
}

