//
// Created by hdani on 25/05/2023.
//

#ifndef SEMESTERB_TASK4_EX3_LINKEDLIST_H
#define SEMESTERB_TASK4_EX3_LINKEDLIST_H
#include "CustomerEmployee.h"
#include "Customer.h"
#include "Employee.h"
class LinkedList
{
private:
    class Node//Internal class.
    {
    public:
        //Methods of the class 'Node'.
        explicit Node(Person* data = nullptr, Node* next = nullptr);//A constructor that creates an object of type 'Node' (default, accepts one parameter and accepts two parameters).
        Node(const Node* other);//Copy constructor of the class 'Node'.
        Person* getData()const{return m_data;}
        Node* getNext()const{return m_next;}
        void setNext(Node* node);
    private:
        //Fields of the class 'Node'.
        Person* m_data;//A pointer to an object of type 'Shape'.
        Node* m_next;//A pointer to an object of type 'Node'.
    };
    //Field of the class 'LinkedList'.
    Node* m_list_head;
public:
    //Methods of the class 'LinkedList'.
    explicit LinkedList(){m_list_head = nullptr;}//Default constructor.
    ~LinkedList();//Destructor.

    /*A method that deletes the list.*/
    void deleteList();

    Node* getListHead(){return m_list_head;}
    void setListHead(Node* listHead){m_list_head = listHead;}
    /*An operator that adds values from one
     list to another and returns the updated list.*/
    LinkedList& operator+=(Person& person);

    /*An operator that prints an object of type 'LinkedList'.*/
    friend ostream& operator<<(ostream &output, LinkedList& thisLinkedList);
};


#endif //SEMESTERB_TASK4_EX3_LINKEDLIST_H
