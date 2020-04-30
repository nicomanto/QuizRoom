#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "myvector.h"
#include "homework.h"
#include "user.h"
using std::string;

class User;

class Course{
private:
    string title;
    string code;
    string subject; //può essere null
    string description; //può essere null
    MyVector<User*> classroom;  // si setta dal file (fa una ricerca nel file XML chiamata con il codice
                                //del corso e scarica tutti gli utenti che hanno aggiunto questo corso      FORSE DA METTERE COSTANTE
    MyVector<Homework*> homew;



    void setCode();
    static string random_code();
public:
    Course(const string& t=string(), const string& s=string(), const string& d=string());
    string getTitle() const;
    string getCode() const;
    string getSubject() const;
    string getDescription() const;
    const MyVector<Homework*>& getHomeworks() const;
    const MyVector<User*>& getClassroom() const;

    void setTitle(const string& t);
    void setSubject(const string& s);
    void setDescription(const string& d);


    void addHomework(Homework* h);
    void removeHomework(Homework* h);

    void addUser(User* h);
    void removeUser(User* h);


    double ShowAllHomeworkStatistics() const;  //La statistica è la percentuale di homework completati.


};

#endif // COURSE_H
