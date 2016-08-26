//
// Created by lgm on 16-8-26.
//

#ifndef POLYMORPHISMINC_PERSON_H
#define POLYMORPHISMINC_PERSON_H

#include <stdlib.h>

typedef  struct _Person Person;
//declaration of pointers to functions
typedef void (*fptrDiaplatInfo)(Person*);
typedef void (*fptrWriteToFile)(Person*, const char*);
typedef void (*fptrDelete)(Person*);

typedef struct _Person {
    void* pDerivedObj;
    char* pFirstName;
    char* pLastName;
    //interface for function
    fptrDiaplatInfo  Display;
    fptrWriteToFile  WriteToFile;
    fptrDelete  Delete;
}Person;

//constructor
Person* new_Person(const char* const pFirstName, const char* const pLastName);
//destructor
void delete_Person(Person* const pPersonObj);
void Person_DisplayInfo(Person* const pPersonObj);

#endif //POLYMORPHISMINC_PERSON_H
