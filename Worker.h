#ifndef WORKER_H
#define WORKER_H
#include <iostream>
using namespace std;
#include "Person.h"

class Worker : public Person {

private:

    int numseniority;

public:
    Worker();
    Worker(int numseniority, int id, string name, string familyName);
    //Worker(const Worker& other);
    ~Worker();
    void printWorker();
    virtual double salary() = 0;
    int getnumseniority();

};
#endif//WORKER_H
