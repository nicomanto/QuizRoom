#include "student.h"

Student::Student(string n, string s, string u, string p, string e): User(n,s,u,p,e){}

bool Student::addCourse() const{
    return false;
}

bool Student::deleteCourse() const{
    return false;
}

bool Student::editCourse() const{
    return false;
}

bool Student::addQuiz() const{
    return false;
}

bool Student::deleteQuiz() const{
    return false;
}

bool Student::editQuiz() const{
    return false;
}

bool Student::doQuiz() const{
    return true;
}

int Student::ShowCourseStatistics(/*input Corso*/) const{
    //ritorna la statistisca su quello che è stato svolto da un SINGOLO studente sul corso
}

int Student::ShowQuizStatistics(/*input Quiz*/) const{
    //ritorna la statistica su quello che è stato svolto da un SINGOLO studente su un quiz
}

Student* Student::clone() const{
    return new Student(*this);
}