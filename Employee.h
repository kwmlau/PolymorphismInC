//
// Created by lgm on 16-8-26.
//

#ifndef POLYMORPHISMINC_EMPLOYEE_H
#define POLYMORPHISMINC_EMPLOYEE_H

#include "Person.h"

typedef struct _Employee{
    Person* pBaseObj;
    char* pDepartment;
    char* pCompany;
    int salary;
}Employee;

Person* new_Employee(const char* pFname, const char* pLName, const char* pDepartment, const char* pCompany, int salary);
void delete_Employee(Person* const pPersonObj);
void Employee_DisplayInfo(Person* const pPersonObj);


#endif //POLYMORPHISMINC_EMPLOYEE_H
