#ifndef CORSO_H
#define CORSO_H
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Model/myvector.h"
#include "Model/user.h"
using std::string;


class Corso{
private:
    string title;
    string code;
    string subject; //può essere null
    string description; //può essere null
    MyVector<User*> classroom;
    //MyVector<Homework*> homew;  //da aggiunere i compiti



    void setCode();
    static string random_code();
public:
    Corso(string t, string s=string(), string d=string());
    string getTitle() const;
    string getCode() const;
    string getSubject() const;
    string getDescription() const;

    void setTitle(string t);
    void setSubject(string s);
    void setDescription(string d);


};

#endif // CORSO_H
