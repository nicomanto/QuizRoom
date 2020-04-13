#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

class Teacher : public User{
private:
    string materia;

public:
    Teacher(string n, string s, string u, string p, string e, string m);
    string getMateria() const;
    void setMateria(string m);

    virtual bool addCourse() const;
    virtual bool deleteCourse() const;
    virtual bool editCourse() const;
    virtual bool addQuiz() const;
    virtual bool deleteQuiz() const;
    virtual bool editQuiz() const;
    virtual bool doQuiz()const;
    virtual int ShowCourseStatistics(/*input Corso*/) const;
    virtual int ShowQuizStatistics(/*input Quiz*/) const;


    Teacher *clone() const;
};

#endif // TEACHER_H
