//#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"


Worker::Worker()
{}
Worker::Worker(int numseniority, int id, string name, string familyName) :Person(id, name, familyName) {

    this->numseniority = numseniority;

}

Worker::~Worker() {


}


void Worker::printWorker() {

    Person::printPerson();

    cout << "salary: " << salary() << endl;
    cout << numseniority << endl;

}


int Worker:: getnumseniority() {
    return numseniority;
}


