#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"

class Student: public User{
public:
    Student();
    Student(const string& n,const string& s,const string& u,const string& p,const string& e);

    virtual bool CanAddCourse() const;
    virtual bool CanDeleteCourse() const;
    virtual bool CanEditCourse() const;

    virtual bool CanAddHomework()const;
    virtual bool CanDeleteHomework() const;
    virtual bool CanEditHomework() const;

    virtual bool CanAddQuiz() const;
    virtual bool CanDeleteQuiz() const;
    virtual bool CanEditQuiz() const;
    virtual bool CanDoQuiz()const;

    virtual double ShowCourseStatistics(const Course& c) const; //da implementare


    Student *clone() const;
};

#endif // STUDENT_H
