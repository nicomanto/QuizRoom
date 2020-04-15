#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"

class Student: public User{
public:
    Student(string n, string s, string u, string p, string e);

    virtual bool addCourse()const;
    virtual bool deleteCourse() const;
    virtual bool editCourse() const;
    virtual bool addQuiz() const;
    virtual bool deleteQuiz() const;
    virtual bool editQuiz() const;
    virtual bool doQuiz()const;
    virtual int ShowCourseStatistics(Course& c) const; //da implementare
    virtual int ShowQuizStatistics(/*input Quiz*/) const;  //da implementare


    Student *clone() const;
};

#endif // STUDENT_H
