//
// Created by lgm on 16-8-26.
//

#include "Employee.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

Person* new_Employee(const char* pFName, const char* pLName, const char* pDepartment, const char* pCompany, int salary)
{
    Employee* pEmpObj;
    Person* pObj;
    pObj = new_Person(pFName, pLName);	//calling base class construtor
    //allocating memory
    pEmpObj = malloc(sizeof(Employee));
    if (pEmpObj == NULL)
    {
        pObj->Delete(pObj);
        return NULL;
    }
    pObj->pDerivedObj = pEmpObj; //pointing to derived object

    //initialising derived class members
    pEmpObj->pDepartment = malloc(sizeof(char)*(strlen(pDepartment)+1));
    strcpy(pEmpObj->pDepartment, pDepartment);
    pEmpObj->pCompany = malloc(sizeof(char)*(strlen(pCompany)+1));
    strcpy(pEmpObj->pCompany, pCompany);
    pEmpObj->salary = salary;

    //Changing base class interface to access derived class functions
    pObj->Delete = delete_Employee;			//Person destructor pointing to destrutor of Employee
    pObj->Display = Employee_DisplayInfo;

    return pObj;
}



void delete_Employee(Person* const pPersonObj)
{
    Employee* pEmpobj;
    pEmpobj = pPersonObj->pDerivedObj;
    //destroy derived obj
    free(pEmpobj->pCompany);
    free(pEmpobj->pDepartment);
    free(pEmpobj);
    //destroy base Obj
    delete_Person(pPersonObj);
}



void Employee_DisplayInfo(Person* const pPersonObj)
{
    Employee* pEmpObj;
    //displaying Person info
    Person_DisplayInfo(pPersonObj);
    pEmpObj = pPersonObj->pDerivedObj;
    //displaying Employee specific info
    printf("Department: %s\n", pEmpObj->pDepartment);
    printf("Company: %s\n", pEmpObj->pCompany);
    printf("salary: %d\n", pEmpObj->salary);
}