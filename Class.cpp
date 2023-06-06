#include "Class.h"
#include"Pupil.h"
#include"Tutor.h"

Class::Class(char cname, int cnum, int studentsnum, Tutor* tutor) {
    this->cname = cname;
    this->cnum = cnum;
    this->studentsnum = studentsnum;
    this->pclass = nullptr;

    this->tutor = tutor;
}

int Class::getstudentnum() const
{
    return studentsnum;
}
int Class::getClassNumber(){
    return cnum;
}
void Class::addTutor(Tutor* t){
    this->tutor = t;
}
Class::Class(char cname, int cnum){
    this->cname = cname;
    this->cnum = cnum;
    this->studentsnum =0;
}

Pupil** Class::getpupils()
{
    return pclass;
}
void Class::addPupil(Pupil* p) {
    if (this->pclass == nullptr) {
        this->pclass = new Pupil * [1];
        this->pclass[0] = p;
        studentsnum++;
    }
    else {
        int news = studentsnum + 1;
        Pupil** arr = new Pupil*[studentsnum];
        for (int i = 0; i < studentsnum; i++) {
            arr[i] = pclass[i];
        }
        delete[]pclass;
        this->pclass = new Pupil * [news];
        for (int i = 0; i < studentsnum; i++) {
            this->pclass[i] = arr[i];
        }
        this->pclass[studentsnum] = p;
        setStudnum(news);

    }
}
void Class::setStudnum(int num) {
    this->studentsnum = num;
}
Pupil* Class::getPupil(int i) {
    return this->pclass[i];
}
