//#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"

Manager::Manager(int numseniority, int id, string name, string familyNam) :Worker(numseniority, id, name, familyNam) {};
double Manager::salary() {

    return basis * 3 + Worker::getnumseniority() * 500;
}
bool Manager::isOutstanding() {
    return Worker::getnumseniority() > 4;
}
void Manager::printManager() {
    Worker::printWorker();
}
