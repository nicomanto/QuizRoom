#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

class Teacher : public User{
private:
    string subject;

public:
    Teacher();
    Teacher(const string& n,const string& s,const string& u,const string& p,const string& e,const string& m=string());
    string getSubject() const;
    void setSubject(const string& m);

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

    virtual double ShowCourseStatistics(const Course& c) const;  //da implementare


    Teacher *clone() const;
};

#endif // TEACHER_H
