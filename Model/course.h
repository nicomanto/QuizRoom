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
    Course(string t, string s=string(), string d=string());
    string getTitle() const;
    string getCode() const;
    string getSubject() const;
    string getDescription() const;

    void setTitle(string t);
    void setSubject(string s);
    void setDescription(string d);


    int ShowStatistics() const;  // da implementare


};

#endif // COURSE_H
