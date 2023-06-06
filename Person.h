#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;
#define basis 4500

class Person {

private:

    int id;
    string name;
    string familyName;


public:

    Person();
    Person(int id, string name, string familyName);
    void printPerson();
    virtual bool isOutstanding()=0;
    string getName();
    int getId();
    string getFamily();
    void setName(string name);
    void setId(int id);
    void setfamilyName(string familyName);
    ~Person();


};

#endif // PERSON_H