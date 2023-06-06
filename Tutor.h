#ifndef TUTOR_H
#define TUTOR_H

#include <iostream>
using namespace std;
#include "Teacher.h"
#include "Class.h"
class Class;
class Tutor :public Teacher {


private:

    Class* classes;

public:

    Tutor(Class* numclass, int numnamee, string* namee,int numseniority, int id, string name, string familyName);
    ~Tutor();
    double salary() ;
    bool isOutstanding() ;
    void printclass();
    void printTutor();


};
#endif //TUTOR_H