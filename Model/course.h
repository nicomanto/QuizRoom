#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "myvector.h"
#include "homework.h"
using std::string;

class User;


class Course{
private:
    string title;
    string code;
    string subject; //può essere null
    string description; //può essere null
    MyVector<User*> classroom;
    MyVector<Homework*> homew;  //da aggiunere i compiti



    void setCode();
    static string random_code();
public:
    Course(const string& t, const string& s=string(), const string& d=string());
    string getTitle() const;
    string getCode() const;
    string getSubject() const;
    string getDescription() const;

    void setTitle(const string& t);
    void setSubject(const string& s);
    void setDescription(const string& d);


    int ShowStatistics() const;  // da implementare


};

#endif // COURSE_H
