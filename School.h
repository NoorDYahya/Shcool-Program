

#ifndef UNTITLED37_SCHOOL_H
#define UNTITLED37_SCHOOL_H
#include <iostream>
using namespace std;
#include "Layer.h"
#include "Person.h"
#include "Pupil.h"
#include "Tutor.h"
#include "Manager.h"
#include "Secretary.h"
class School {
private:
    Layer** layers;
    int numlayers = 6;
    Person** people;
    int numpeople;
    bool isManeger;
    bool checkIfExit(int id);
    void allocateMemory();
    void menuHelper(int i);
    void printMenu();
    void printPeople(Person* p);
    double minSalaryH();

public:
    School();
    ~School();
    void Menu();


};

#endif //UNTITLED37_SCHOOL_H
