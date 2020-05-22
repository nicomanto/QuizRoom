#ifndef VECTORUSERS_H
#define VECTORUSERS_H

#include <stdexcept>

#include "teacher.h"
#include "student.h"
#include "myvector.h"
#include "timescorehomework.h"

#include <QStackedWidget>


class PrincipalForm;

class Controller{
private:
    MyVector<User*> users;
    MyVector<Course* > course;
    MyVector<PrincipalForm*> stack_page;

public:
    Controller();
    ~Controller();

    void addStackView(PrincipalForm* p);
    PrincipalForm* removeStackView();
    void cleanStack();

    PrincipalForm* getPreviousPage();

    void addCourse(User* s, const string& t, const string& d);
    void modifyCourse(Course* c,const string& t,const string& d);
    void deleteCourse(User* s, unsigned int i);
    void deleteCourse(Course* c);

    void AddHomework(Course* c, const string& t, const string& d, bool time, bool score, const DateTime& deadline);
    void modifyHomework(Homework* h,const string& t,const string& d);
    void deleteHomework(Course* c, unsigned int i);
    void deleteHomework(Homework* h);





    User* getUser(const string& u, const string& p) const;
};

#endif // VECTORUSERS_H
