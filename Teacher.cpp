//#define _CRT_SECURE_NO_WARNINGS
#include "Teacher.h"


Teacher::Teacher(int numnamee , string* namee,int numseniority, int id,
                 string name, string familyName): Worker(numseniority,id,
                                                         name, familyName){

    this->numOfSub = numnamee;
    this->subjects = new string[this->numOfSub];
    for (int i = 0; i < this->numOfSub; i++) {
        this->subjects[i] = namee[i];
    }
}

Teacher::~Teacher() {


}

Teacher::Teacher() {

    subjects = nullptr;
    numOfSub = 0;
}
double Teacher::salary() {

    return double(basis) * (1 + double(numOfSub / 10)) + 200 *double( Worker::getnumseniority());
}

void Teacher::printpro() {

    for (int i = 0; i < numOfSub; i++) {

        cout << subjects[i]<< " ";
    }


}

void Teacher::printall() {

    Worker::printWorker();
    cout << numOfSub << endl;
    Teacher::printpro();

}
bool Teacher::isOutstanding()
{
    return this->numOfSub > 5;
}