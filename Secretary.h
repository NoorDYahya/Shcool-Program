//
// Created by noor dar yahya on 04/06/2023.
//

#ifndef UNTITLED37_SECRETARY_H
#define UNTITLED37_SECRETARY_H
#include <iostream>
using namespace std;
#include "Worker.h"

class Secretary: public Worker {
private:
    int numStud;

public:
    Secretary(int numseniority, int id, string name, string familyNam,int numStud);
    double salary();
    bool isOutstanding();
    void printSec();
    ~Secretary();

};

#endif //UNTITLED37_SECRETARY_H
