#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection = 0;
    vector<Student *> studentList;
    string name;
    int age;

    do
    {
        cout<<endl;
        cout<<"Valitse toiminto"<<endl;
        cout<<"Lisaa opiskelija = 0"<<endl;
        cout<<"Tulosta kaikki opiskelijat = 1"<<endl;
        cout<<"Jarjesta nimen mukaan = 2"<<endl;
        cout<<"Jarjesta ian mukaan = 3"<<endl;
        cout<<"Etsi opiskelija = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
        {
            cout<<"Anna nimi:"<<endl;
            cin>>name;
            cout<<"Anna ika:"<<endl;
            cin>>age;
            studentList.emplace_back(new Student(name,age));
            break;
        }
        case 1:
        {
            for(auto& student : studentList)
            {
                student->printStudentInfo();
            }
            break;
        }
        case 2:
        {
            sort(studentList.begin(), studentList.end(),
                 [](Student * a, Student * b){ return a->getName() < b->getName(); });

            for(auto& student : studentList)
            {
                student->printStudentInfo();
            }
            break;
        }
        case 3:
        {
            sort(studentList.begin(), studentList.end(),
                 [](Student * a, Student * b){ return a->getAge() < b->getAge(); });

            for(auto& student : studentList)
            {
                student->printStudentInfo();
            }
            break;
        }
        case 4:
        {
            cout<<"Anna haettavan opiskelijan nimi:"<<endl;
            cin>>name;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [name](Student * student){
                                  return name == student->getName();
                              });

            if(it != studentList.end())
            {
                cout<<"Opiskelija loytyi:"<<endl;
                (*it)->printStudentInfo();
            }
            else
            {
                cout<<"Opiskelijaa ei loytynyt"<<endl;
            }
            break;
        }
        default:
            cout<<"Virhe, ohjelma sulkeutuu"<<endl;
            break;
        }
    }
    while(selection < 5);

    for(auto& student : studentList)
    {
        delete student;
    }

    return 0;
}
