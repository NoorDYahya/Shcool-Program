
#include "Pupil.h"


Pupil::~Pupil() {

    delete[]greades;
}
Pupil::Pupil(Pupil& p) {
    this->greades = p.greades;
    this->greades2 = p.greades2;
    this->layer = p.layer;
    this->numclass = p.numclass;
    this->greades = new int[p.greades2];
    for (int i = 0; i < p.greades2; i++) {
        this->greades[i] = p.greades[i];
    }
}
Pupil::Pupil(){}
Pupil::Pupil(int* greades, int greades2, char layer, int numclass
        , int id, string name, string familyName): Person(id,name,familyName)
{

    this->greades = greades;
    this->greades2 = greades2;
    this->layer = layer;
    this->numclass = numclass;
    this->greades = new int[greades2];
    for (int i = 0; i < greades2; i++) {
        this->greades[i] = greades[i];
    }

}

double Pupil::avg() {
    double sumgreades = 0;
    for (int i = 0; i < greades2; i++) {

        sumgreades += greades[i];

    }
    return sumgreades / greades2;


}
void Pupil::printPupil() {

    printPerson();

    cout << "number of grades is :" <<greades2<< " with average :"<<avg() << "," << "the pupil study in the layer: " << layer << "," << "and number of class :" << numclass << endl;
    cout << "student grades is : " << endl;
    for (int i = 0; i < greades2; i++) {
        cout << i + 1 << ") " << greades[i] << endl;
    }
}

bool Pupil::isOutstanding()
{
    for(int i = 0 ; i < greades2 ; i++){
        if(greades[i] < 70){
            return false;
        }
    }
    return avg() > 85;
}
