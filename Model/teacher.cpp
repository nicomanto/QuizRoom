#include "teacher.h"

Teacher::Teacher(string n, string s, string u, string p, string e, string m): User(n,s,u,p,e), subject(m){}

string Teacher::getSubject() const{
    return subject;
}

void Teacher::setSubject(string m){
    subject=m;
}

bool Teacher::addCourse() const{
    return true;
}

bool Teacher::deleteCourse() const{
    return true;
}

bool Teacher::editCourse() const{
    return true;
}

bool Teacher::addQuiz() const{
    return true;
}

bool Teacher::deleteQuiz() const{
    return true;
}

bool Teacher::editQuiz() const{
    return true;
}

bool Teacher::doQuiz() const{
    return false;
}

int Teacher::ShowCourseStatistics(/*input Corso*/) const{
    //ritorna la statistisca su quello che è stato svolto da TUTTI gli studenti del corso
}

int Teacher::ShowQuizStatistics(/*input Quiz*/) const{
    //ritorna la statistica su quello che è stato svolto da TUTTI gli studenti su un quiz
}

Teacher *Teacher::clone() const{
    return new Teacher(*this);
}
