//
// Created by hdani on 25/05/2023.
//

#include "LinkedList.h"

/*A constructor that creates an object of type 'Node'
  (default, accepts one parameter and accepts two parameters).*/
LinkedList::Node::Node(Person *data, LinkedList::Node *next)
{
    if (data != nullptr)
    {
        // Check the type of the data and perform dynamic_cast accordingly
        if (typeid(*data) == typeid(Employee))
            m_data = dynamic_cast<Employee*>(data);
        else if (typeid(*data) == typeid(Customer))
            m_data = dynamic_cast<Customer*>(data);
        else
            m_data = dynamic_cast<CustomerEmployee*>(data);
    }
    else
        m_data = nullptr;
    m_next = next;
}

/*Copy constructor of the class 'Node'.*/
LinkedList::Node::Node(const LinkedList::Node* other)
{
    if (other != nullptr)
    {
        if (other->m_data != nullptr)
        {
            // Check the type of the data and perform dynamic_cast accordingly
            if (typeid(other->m_data) == typeid(Employee))
                m_data = dynamic_cast<Employee*>(other->m_data);
            else if (typeid(*other->m_data) == typeid(Customer))
                m_data = dynamic_cast<Customer*>(other->m_data);
            else
                m_data = dynamic_cast<CustomerEmployee*>(other->m_data);
        }
        else
            m_data = nullptr;
        m_next = other->m_next;
    }
    else
    {
        m_data = nullptr;
        m_next = nullptr;
    }
}

void LinkedList::Node::setNext(LinkedList::Node *node)
{
    // Create a new Node object as the next node
    m_next = new Node(node);
}

/* Destructor for the LinkedList class. */
LinkedList::~LinkedList()
{
    deleteList();
}

/*A method that deletes the list.*/
void LinkedList::deleteList()
{
    /*Running through all the members of the list and
      deleting the dynamic assignments of each member.*/
    Node* temp = m_list_head;
    while (temp != nullptr)
    {
        Node* next = temp->getNext();
        delete[]temp;
        temp = next;
    }
    m_list_head = nullptr;
}

/*An operator that adds values from one
 list to another and returns the updated list.*/
LinkedList& LinkedList::operator+=(Person& person)
{
    Node* newPerson = new Node(&person);
    if (m_list_head != nullptr)//Checking if the list is not empty.
    {
        Node* temp = m_list_head;
        while (temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(newPerson);
    }
    else//If the list is empty.
        m_list_head = newPerson;
    return *this;//Returning the new list.
}

/*An operator that prints an object of type 'LinkedList'.*/
ostream &operator<<(ostream &output, LinkedList &thisLinkedList)
{
    /*Running through the entire list and inserting its members into
      the 'output' variable with the enter character between members.*/
    int i = 1;
    output << "The persons:" << endl;
    output << "====================" << endl << endl;
    if (thisLinkedList.m_list_head != nullptr)
    {
        LinkedList temp(thisLinkedList);
        while (temp.m_list_head != nullptr)
        {
            output << "Person number " << i << ":" << endl;
            ++i;
            output << *(temp.m_list_head)->getData() << endl;
            if (temp.m_list_head->getNext() != nullptr)
                output << "--------------------" << endl << endl;
            temp.m_list_head = temp.m_list_head->getNext();
        }
    }
    else
        output << endl;
    output << "====================" << endl;
    return output;
}