#ifndef TEACHER_H
#define TEACHER_H
#include "user.h"

class Teacher : public User{
public:
    Teacher();
    Teacher(const string& u,const string& p);

    virtual bool CanAddCourse() const;
    virtual bool CanDeleteCourse() const;
    virtual bool CanEditCourse() const;

    virtual bool CanAddHomework()const;
    virtual bool CanDeleteHomework() const;
    virtual bool CanEditHomework() const;

    virtual bool CanAddQuiz() const;
    virtual bool CanDeleteQuiz() const;
    virtual bool CanEditQuiz() const;
    //virtual bool CanDoQuiz()const;


    Teacher *clone() const;
};

#endif // TEACHER_H
