//#define _CRT_SECURE_NO_WARNINGS
#include "Tutor.h"
#include "Class.h"
#include "Pupil.h"
Tutor::Tutor(Class* numclass, int numnamee, string* namee,int numseniority, int id, string name, string familyName):Teacher
(numnamee,namee,numseniority,  id,  name,  familyName){

    this->classes = numclass;

}

Tutor::~Tutor(){


}

double Tutor::salary(){


    return Teacher::salary() + 1200;
}

bool Tutor::isOutstanding() {

    int count = 0;
    int per = 0.6 * (*classes).getstudentnum();
    for (int i = 0; i < (*classes).getstudentnum(); i++) {

        if (classes->getPupil(i)->isOutstanding()) {
            count++;
        }
    }
    return count > per;

}

void Tutor::printclass(){

    for (int i = 0; i < (*classes).getstudentnum(); i++) {
        if ((*classes).getPupil(i)->isOutstanding()) {
            (*classes).getPupil(i)->printPupil();
            cout << " and he is outstanding pupil" << endl;
        }
        else {
            (*classes).getPupil(i)->printPupil();
        }


    }


}

void Tutor::printTutor(){

    Teacher::printpro();
    Worker::printWorker();
    cout << "student that the tutor teach:"<<endl;
    for (int i = 0; i < (*classes).getstudentnum(); i++) {

        (*classes).getPupil(i)->printPupil();

    }
}


