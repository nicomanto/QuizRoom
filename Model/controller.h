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

    void deleteCourse(User* s, unsigned int i);
    void deleteCourse(Course* c);

    void addCourse(User* s, string t, string d);

    User* getUser(const string& u, const string& p) const;
};

#endif // VECTORUSERS_H
