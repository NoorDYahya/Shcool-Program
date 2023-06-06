
#ifndef PUPIL_H
#define PUPIL_H

#include <iostream>
using namespace std;
#include "Person.h"
#include "string"
class Pupil : public Person {

private:
    int* greades;
    int greades2;
    char layer;
    int numclass;

public:

    ~Pupil();
    Pupil();
    Pupil(Pupil& p);
    Pupil(int* graedes, int greades2, char layer, int numclass, int id, string name, string familyName);
    double avg();
    void printPupil();
    bool isOutstanding() ;


};

#endif //PUPIL_H