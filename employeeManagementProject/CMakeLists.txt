cmake_minimum_required(VERSION 3.23)
project(employeeManagementProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(employeeManagementProject main.cpp Person.cpp Person.h Employee.cpp Employee.h Customer.cpp Customer.h CustomerEmployee.cpp CustomerEmployee.h LinkedList.cpp LinkedList.h)
