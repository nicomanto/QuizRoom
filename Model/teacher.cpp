#include "teacher.h"
#include "student.h"
Teacher::Teacher(){}

Teacher::Teacher(const string& u,const string& p): User(u,p){}

bool Teacher::CanAddHomework() const{
    return true;
}

bool Teacher::CanDeleteHomework() const{
    return true;
}

bool Teacher::CanEditHomework() const{
    return true;
}

bool Teacher::CanAddCourse() const{
    return true;
}

bool Teacher::CanDeleteCourse() const{
    return true;
}

bool Teacher::CanEditCourse() const{
    return true;
}

bool Teacher::CanAddQuiz() const{
    return true;
}

bool Teacher::CanDeleteQuiz() const{
    return true;
}

bool Teacher::CanEditQuiz() const{
    return true;
}

Teacher* Teacher::clone() const{
    return new Teacher(*this);
}
