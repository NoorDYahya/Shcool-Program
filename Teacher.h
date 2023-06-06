#include <iostream>
using namespace std;
#include "Worker.h"

class Teacher : public Worker {

private:

    int numOfSub;
    string* subjects;


public:

    Teacher(int numnamee , string* namee,int numseniority, int id, string name, string familyName);
    ~Teacher();
    Teacher();
    double salary();
    void printpro();
    void printall();
    bool isOutstanding() ;



};
