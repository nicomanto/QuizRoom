#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "myvector.h"
#include "homework.h"

using std::string;


class Course{
private:
    string title;
    string code;
    string description; //può essere null
    MyVector<Homework*> homew;

    static const string random_code();
public:
    Course(const string& t=string(), const string& d=string());

    const string& getTitle() const;
    const string& getCode() const;
    const string& getDescription() const;
    const MyVector<Homework*>& getHomeworks() const;

    void setTitle(const string& t);
    void setDescription(const string& d);
    void setCode();

    void addHomework(Homework* h);
    void removeHomework(Homework* h);

};

#endif // COURSE_H
