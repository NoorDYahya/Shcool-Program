#include "School.h"

School::School()
{
    this->layers = new Layer *[numlayers];

    layers[0] = new Layer('a');
    layers[1] = new Layer('b');
    layers[2] = new Layer('c');
    layers[3] = new Layer('d');
    layers[4] = new Layer('e');
    layers[5] = new Layer('f');
    this->people = nullptr;
    this->isManeger = false;
    this->numpeople = 0;

}

bool School::checkIfExit(int id)
{
    if (numpeople == 0)
    {
        return false;
    }

    for (int i = 0; i < numpeople; i++)
    {
        if (people[i]->getId() == id)
        {
            return true;
        }
    }
    return false;
}

void School::allocateMemory()
{
    if (this->people == nullptr)
    {
        this->people = new Person *[1];
    } else
    {
        Person **p = new Person *[numpeople];
        for (int i = 0; i < numpeople; i++)
        {
            p[i] = this->people[i];
        }
        delete people;
        people = new Person *[numpeople + 1];
        for (int i = 0; i < numpeople; i++)
        {
            people[i] = p[i];
        }
    }
}

void School::printPeople(Person* p){

        if(typeid(*p) == typeid(Pupil)){
            dynamic_cast<Pupil*>(p)->printPupil();
        }
        if(typeid(*p) == typeid(Teacher)){
            dynamic_cast<Teacher*>(p)->printall();
        }
        if(typeid(*p) == typeid(Tutor)){
            dynamic_cast<Tutor*>(p)->printTutor();
        }
        if(typeid(*p) == typeid(Manager)){
            dynamic_cast<Manager*>(p)->printManager();
        }
        if(typeid(*p) == typeid(Secretary)){
            dynamic_cast<Secretary*>(p)->printSec();
        }

}
double School::minSalaryH(){
    double min ;
    for(int j = 0 ; j < numpeople ; j++){
        if(typeid(*people[j]) == typeid(Teacher)){
            min = dynamic_cast<Teacher*>(people[j])->salary();
        }
        if(typeid(*people[j]) == typeid(Tutor)){
            min = dynamic_cast<Tutor*>(people[j])->salary();
        }
        if(typeid(*people[j]) == typeid(Manager)){
            min = dynamic_cast<Manager*>(people[j])->salary();
        }
        if(typeid(*people[j]) == typeid(Secretary)){
            min = dynamic_cast<Secretary*>(people[j])->salary();
        }
    }
    return min;
}
void School::menuHelper(int i)
{
    if (i == 1)
    {
        int id, numOfGrades, clas;
        char layer;
        string name, family;
        cout << "enter you name and your family name ";
        cin >> name >> family;
        cout << endl;
        cout << "choose layer , class , id , number of grades:";
        cin >> layer >> clas >> id >> numOfGrades;
        if (checkIfExit(id))
        {
            cout << "this person is aleardy exist , cant add him" << endl;
            return;
        }


        int *grades = new int[numOfGrades];
        cout << "enter your grades:";
        for (int j = 0; j < numOfGrades; j++)
        {
            cin >> grades[j];
        }
        Pupil* pupil = new Pupil(grades, numOfGrades, layer, clas, id,
                                 name,
                                 family);
        for( int k = 0 ; k < 6 ; k++){
            if( layer == layers[k]->getLayerName()){
                layers[k]->getclass(clas-1)->addPupil(pupil);
                layers[k]->getclass(clas-1)->setStudnum(layers[k]->getclass
                (clas)->getstudentnum()+1);
            }
        }
        allocateMemory();
        people[numpeople] = pupil;
        numpeople++;



    }
    if (i == 2)
    {
        int numofSubjects, numseniority, id;
        string *subjects;
        string name, familyName;
        cout << "enter you name and your family name ";
        cin >> name >> familyName;
        cout << "enter TEACHER'S id, number of subjects and years of "
                "seniority ";
        cin >> id >> numofSubjects >> numseniority;
        if (checkIfExit(id))
        {
            cout << "this person is aleardy exist , cant add him" << endl;
            return;
        }
        subjects = new string[numofSubjects];
        cout << "enter teacher subjects :";
        for (int j = 0; j < numofSubjects; j++)
        {
            cin >> subjects[j];
        }
        allocateMemory();
        people[numpeople] = new Teacher(numofSubjects, subjects,
                                        numseniority,
                                        id, name, familyName);
        numpeople++;


    }
    if(i == 3){
        Class* classs = nullptr;
        int numOfsubjects, numseniority,id ,clas;
        string* subjects;
        string name,  familyName;
        cout << "enter you name and your family name ";
        cin >> name >> familyName;
        cout << "enter TEACHER'S id, number of subjects and years of "
                "seniority ";
        cin >> id >> numOfsubjects >> numseniority;
        if (checkIfExit(id))
        {
            cout << "this person is aleardy exist , cant add him" << endl;
            return;
        }
        subjects = new string[numOfsubjects];
        cout << "enter teacher subjects :";
        for (int j = 0; j < numOfsubjects; j++)
        {
            cin >> subjects[j];
        }
        cout << "enter class and layer :";
        char layer;
        cin >> clas >> layer;

        for(int k = 0 ; k < 6 ;k++){
            if(layers[k]->getLayerName() == layer){
                classs = layers[k]->getclass(clas-1);
            }
        }
        Tutor* tutor = new Tutor(classs,numOfsubjects,subjects,numseniority,
                                 id,name,familyName);
        for( int k = 0 ; k < 6 ; k++){
            if( layer == layers[k]->getLayerName()){
                layers[k]->getclass(clas-1)->addTutor(tutor);

            }
        }
        allocateMemory();
        people[numpeople] = tutor;
        numpeople++;


    }
    if(i == 4){
        int numseniority, id ;
        string name,  familyNam;
        cout << "enter maneger name and  family name ";
        cin >> name >> familyNam;
        cout << "enter Maneger's number of seniority and id ";
        cin >> numseniority>> id;
        allocateMemory();
        Manager * m = new Manager(numseniority,id, name , familyNam);
        people[numpeople] = m;
        isManeger = true;
        numpeople++;
    }
    if(i ==5){
        int numseniority, id, numStud;
        string name,  familyNam;
        cout << "enter secretary name and  family name ";
        cin >> name >> familyNam;
        cout << "enter secretary's number of seniority and id and number of "
                "children studing in the school ";
        cin >> numseniority>> id >> numStud;
        Secretary* s = new Secretary(numseniority, id ,name, familyNam,
                                     numStud);

        people[numpeople] = s;
        numpeople++;


    }
    if(i == 6){
        for(int j = 0 ; j < numpeople ; j++){
            printPeople(people[j]);
        }
    }
    if(i == 7){
        for(int j = 0 ; j < numpeople ; j++){
            if(people[j]->isOutstanding()){
                printPeople(people[j]);
            }
        }
    }
    if(i==8){
        int id;
        cout << "entre id of the tutor:";
        cin >> id;
        if(!checkIfExit(id)){
           cout<< "this tutor is not exist in this school"<<endl;
        }
        else{
            for(int j = 0 ; j < numpeople ; j++){
                if(people[j]->getId() == id){
                    if(typeid(*people[j]) == typeid(Tutor)){
                        dynamic_cast<Tutor*>(people[j])->printTutor();
                    }
                }
            }
        }
    }
    if(i==9){
        double min =minSalaryH();
        Person* tmp = nullptr;
        for(int j = 0 ; j < numpeople ; j++){
            if(typeid(*people[j]) == typeid(Teacher)){
                if(dynamic_cast<Teacher*>(people[j])->salary() <= min){
                    min = dynamic_cast<Teacher*>(people[j])->salary();
                    tmp = people[j];
                }
            }
            if(typeid(*people[j]) == typeid(Tutor)){
                if(dynamic_cast<Tutor*>(people[j])->salary() <= min){
                    min = dynamic_cast<Tutor*>(people[j])->salary();
                    tmp = people[j];
                }
            }
            if(typeid(*people[j]) == typeid(Manager)){
                if(dynamic_cast<Manager*>(people[j])->salary() <=min){
                    min = dynamic_cast<Manager*>(people[j])->salary();
                    tmp = people[j];
                }
            }
            if(typeid(*people[j]) == typeid(Secretary)){
                if(dynamic_cast<Secretary*>(people[j])->salary()<= min){
                    min = dynamic_cast<Secretary*>(people[j])->salary();
                    tmp = people[j];
                }
            }
        }
        cout << "the minimun salary id :" <<min << "and the worker is "
                                                   ":"<<endl;
        printPeople(tmp);
    }

}

void School::printMenu()
{
    cout << "choose one of the options:" << endl;
    cout << "1- add pupil " << endl << "2- add teacher " << endl
         << "3- add Totur " <<
         endl << "4- add manager " << endl << "5- add secretary " << endl
         << "6- print pupil and workers " << endl <<
         "7- print outstanding people " << endl <<
         "8- prtint totur's class" << endl
         << "9- print worker details with smallest sallary " << endl
         << "10- Exit." << endl;
}

School::~School()
{}

void School::Menu()
{
    printMenu();
    int num;
    cin >> num;
    while (num != 10)
    {

        menuHelper(num);
        printMenu();
        cin >> num;


    }
    if (num == 10)
    {
        return;
    }
}
