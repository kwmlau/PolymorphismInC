//
// Created by lgm on 16-8-26.
//

#include "Person.h"
#include "Employee.h"

int main()
{
    Person* PersonObj = new_Person("Anjali", "Jaiswal");
    Person* EmployeeObj = new_Employee("Gauri", "Jaiswal","HR", "TCS", 40000);

    //accessing Person object
    //displaying Person info
    PersonObj->Display(PersonObj);
    //calling destructor
    PersonObj->Delete(PersonObj);

    //accessing to employee object
    //displaying employee info
    EmployeeObj->Display(EmployeeObj);
    //calling destrutor
    EmployeeObj->Delete(EmployeeObj);
    return 0;
}