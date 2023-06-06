

#include "Person.h"
#include <iostream> // Add this include for 'cout' and 'endl'
#include <string>
Person::Person(int id, string name, string familyName) {

    this->id = id;
    this->name = name;
    this->familyName = familyName;


}

Person::Person() {
    this->id = 0;
    this->name = "";
    this->familyName = "";


}

Person::~Person() {

}


void Person::printPerson() {

    cout << id << "," << name << "," << familyName << endl;
}

void Person::setId(int id) {

    this->id = id;
}
void Person::setName(string name) {

    this->name = name;
}
void Person::setfamilyName(string familyName) {

    this->familyName = familyName;
}
string Person::getName() {

    return name;
}
int Person:: getId() {

    return id;
}
string Person::getFamily() {
    return familyName;
}
