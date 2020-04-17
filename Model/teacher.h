#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

class Teacher : public User{
private:
    string subject;

public:
    Teacher(const string& n,const string& s,const string& u,const string& p,const string& e,const string& m);
    string getSubject() const;
    void setSubject(const string& m);

    virtual bool addCourse() const;
    virtual bool deleteCourse() const;
    virtual bool editCourse() const;
    virtual bool addQuiz() const;
    virtual bool deleteQuiz() const;
    virtual bool editQuiz() const;
    virtual bool doQuiz()const;
    virtual int ShowCourseStatistics(const Course& c) const;  //da implementare
    virtual int ShowQuizStatistics(/*input Quiz*/) const;  //da implementare


    Teacher *clone() const;
};

#endif // TEACHER_H
