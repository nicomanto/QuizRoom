#ifndef USER_H
#define USER_H
#include "myvector.h"
#include <string>
#include "course.h"
using std::string;

class User {
private:
    string name;
    string surname;
    string username;
    string password;
    string email;
    MyVector<Course*> course; // da mettere dopo che è stata creata l'opportuna classe;
public:
    User(const string& n,const string& s,const string& u,const string& p,const string& e); //da aggiungere i corsi

    string getName() const;
    string getSurname() const;
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    MyVector<Course*> getCourse() const;  //da implementare

    void setName(const string& n);
    void setSurname(const string& s);
    void setUsername(const string& u);
    void setPassword(const string& p);
    void setEmail(const string& e);

    virtual bool addCourse()const =0;
    virtual bool deleteCourse() const=0;
    virtual bool editCourse() const=0;
    virtual bool addQuiz() const=0;
    virtual bool deleteQuiz() const=0;
    virtual bool editQuiz() const=0;
    virtual bool doQuiz() const=0;
    virtual int ShowCourseStatistics(const Course& c) const=0; //implementazione diverse per teacher o student
    virtual int ShowQuizStatistics(/*input Quiz*/) const=0; //implementazione diverse per teacher o student
    virtual User* clone() const=0;
    virtual ~User();


    bool operator == (const User& u) const; //da aggiungere i corsi
    bool operator != (const User& u) const; //da aggiungere i corsi
};

#endif // USER_H
