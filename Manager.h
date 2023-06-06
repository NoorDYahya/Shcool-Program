
#ifndef UNTITLED37_MANAGER_H
#define UNTITLED37_MANAGER_H
#include "Worker.h"
#include <iostream>
using namespace std;
class Manager : public Worker {
private:

public:
    Manager(int numseniority, int id, string name, string familyNam);
    ~Manager();
    double salary();
    bool isOutstanding();
    void printManager();

};

#endif //UNTITLED37_MANAGER_H
