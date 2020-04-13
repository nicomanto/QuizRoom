#ifndef USER_H
#define USER_H
#include "myvector.h"
#include <string>

using std::string;

class User {
private:
    string name;
    string surname;
    string username;
    string password;
    string email;
    //MyVector<*Corsi>   // da mettere dopo che è stata creata l'opportuna classe;
public:
    User(string n, string s, string u, string p, string e); //da aggiungere i corsi

    string getName() const;
    string getSurname() const;
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    //MyVector<*Corsi> () const;

    void setName(string n);
    void setSurname(string s);
    void setUsername(string u);
    void setPassword(string p);
    void setEmail(string e);
    //da aggiungere i corsi

    virtual bool addCourse()const =0;
    virtual bool deleteCourse() const=0;
    virtual bool editCourse() const=0;
    virtual bool addQuiz() const=0;
    virtual bool deleteQuiz() const=0;
    virtual bool editQuiz() const=0;
    virtual bool doQuiz() const=0;
    virtual int ShowCourseStatistics(/*input Corso*/) const=0; //implementazione diverse per teacher o student
    virtual int ShowQuizStatistics(/*input Quiz*/) const=0; //implementazione diverse per teacher o student
    virtual User* clone() const=0;
    virtual ~User() {}


    bool operator == (const User& u) const; //da aggiungere i corsi
    bool operator != (const User& u) const; //da aggiungere i corsi
};

#endif // USER_H
