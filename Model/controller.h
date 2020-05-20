#ifndef VECTORUSERS_H
#define VECTORUSERS_H

#include <stdexcept>

#include "teacher.h"
#include "student.h"
#include "myvector.h"
#include "timescorehomework.h"

class Controller{
private:
    MyVector<User*> users;

public:
    Controller();
    ~Controller();


    void addCourse(User* s, const string& t, const string& d);
    void modifyCourse(Course* c,const string& t,const string& d);
    void deleteCourse(User* s, unsigned int i);
    void deleteCourse(Course* c);

    void AddHomework(Course* c, const string& t, const string& d, bool time, bool score, const DateTime& deadline);
    void deleteHomework(Course* c, unsigned int i);





    User* getUser(const string& u, const string& p) const;
};

#endif // VECTORUSERS_H
