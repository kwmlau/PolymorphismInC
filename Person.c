//
// Created by lgm on 16-8-26.
//

#include <stddef.h>
#include "Person.h"
#include <stdio.h>
#include <string.h>

Person* new_Person(const char* const pFName, const char* const pLName){
    Person* pObj = NULL;
    pObj = (Person*)malloc(sizeof(Person));
    if(pObj == NULL){
        printf("对象申请内存失败!\n");
        return NULL;
    }
    pObj->pDerivedObj = pObj;

    pObj->pFirstName = (char*)malloc(sizeof(strlen(pFName) + 1));
    strcpy(pObj->pFirstName, pFName);
    pObj->pLastName = (char*)malloc(sizeof(strlen(pLName) + 1));
    strcpy(pObj->pLastName, pLName);

    pObj->Display = Person_DisplayInfo;
    pObj->Delete = delete_Person;

    return pObj;
}

void delete_Person(Person* const pPersonObj){
    if(pPersonObj!= NULL){
        free(pPersonObj->pFirstName);
        free(pPersonObj->pLastName);
        free(pPersonObj);
    }
}

void Person_DisplayInfo(Person* const pPersonObj){
    printf("FirstName: %s\n", pPersonObj->pFirstName);
    printf("LastName: %s\n", pPersonObj->pLastName);
}