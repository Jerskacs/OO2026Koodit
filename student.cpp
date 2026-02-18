#include "student.h"
#include <iostream>

Student::Student(std::string n, int a)
{
    Name = n;
    Age = a;
    std::cout<<"Luotiin opiskelija "<<Name<<", ika "<<Age<<std::endl;
}

Student::~Student()
{
    std::cout<<"Poistettiin opiskelija "<<Name<<", ika "<<Age<<std::endl;
}

void Student::setAge(int a)
{
    Age = a;
}

void Student::setName(std::string s)
{
    Name = s;
}

std::string Student::getName() const
{
    return Name;
}

int Student::getAge() const
{
    return Age;
}

void Student::printStudentInfo() const
{
    std::cout<<"Opiskelija "<<Name<<" ("<<Age<<" v)"<<std::endl;
}

