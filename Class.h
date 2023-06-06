#ifndef CLASS_H
#define CLASS_H

#include <iostream>
class Tutor;
class Pupil;
using namespace std;
class Class {

private:
    char cname;
    int cnum;
    Pupil** pclass ;
    int studentsnum;
    Tutor* tutor;
public:
    Class(char cname, int cnum,int studentsnum, Tutor* tutor);
    Class(char cname, int cnum);
    ~Class();
    int getstudentnum() const;
    Pupil** getpupils();
    void addPupil(Pupil* p);
    Pupil* getPupil(int i);
    void setStudnum(int num);
    int getClassNumber();
    void addTutor(Tutor* t);
};

#endif // CLASS_H