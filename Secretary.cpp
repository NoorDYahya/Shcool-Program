#include "Secretary.h"
Secretary::Secretary(int numseniority, int id, string name, string familyNam, int numStud) :Worker(numseniority, id, name, familyNam) {
    this->numStud = numStud;
}
double Secretary::salary() {
    return basis * this->numStud * 250;
}
bool Secretary::isOutstanding() {
    int a = Worker::getnumseniority();
    return  a> 15;
}
void Secretary::printSec() {
    Worker::printWorker();
}
Secretary::~Secretary(){}
