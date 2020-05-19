#include "student.h"

Student::Student(){}

Student::Student(const string& u,const string& p): User(u,p){}

bool Student::CanAddHomework() const{
  return false;
}

bool Student::CanDeleteHomework() const{
    return false;
}

bool Student::CanEditHomework() const{
    return false;
}

bool Student::CanAddCourse() const{
    return false;
}

bool Student::CanDeleteCourse() const{
    return false;
}

bool Student::CanEditCourse() const{
    return false;
}

bool Student::CanAddQuiz() const{
    return false;
}

bool Student::CanDeleteQuiz() const{
    return false;
}

bool Student::CanEditQuiz() const{
    return false;
}

bool Student::CanDoQuiz() const{
    return true;
}

double Student::ShowCourseStatistics(const Course &c) const{
    for(int i=0; i<course.size();++i){
        if(course[i]->getTitle()==c.getTitle())
            return course[i]->ShowAllHomeworkStatistics();


    }

    return 0;
}

Student* Student::clone() const{
    return new Student(*this);
}
