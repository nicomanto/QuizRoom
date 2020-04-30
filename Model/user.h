#ifndef USER_H
#define USER_H
#include "myvector.h"
#include <string>
#include "course.h"

class Course;
using std::string;
class User {
protected:
    string name;
    string surname;
    string username;
    string password;
    string email;
    MyVector<Course> course; // da mettere dopo che è stata creata l'opportuna classe;
public:
    User();
    User(const string& n,const string& s,const string& u,const string& p,const string& e); //da aggiungere i corsi

    string getName() const;
    string getSurname() const;
    string getUsername() const;
    string getPassword() const;
    string getEmail() const;
    const MyVector<Course>& getCourse() const;  //da implementare

    void setName(const string& n);
    void setSurname(const string& s);
    void setUsername(const string& u);
    void setPassword(const string& p);
    void setEmail(const string& e);

    virtual bool CanAddCourse()const =0;
    virtual void addCourse(const Course& c);
    virtual bool CanDeleteCourse() const=0;
    virtual void deleteCourse(const Course& c);
    virtual bool CanEditCourse() const=0;

    virtual bool CanAddHomework()const =0;
    virtual bool CanDeleteHomework() const=0;
    virtual bool CanEditHomework() const=0;

    virtual bool CanAddQuiz() const=0;
    virtual bool CanDeleteQuiz() const=0;
    virtual bool CanEditQuiz() const=0;
    virtual bool CanDoQuiz() const=0;


    virtual double ShowCourseStatistics(const Course& c) const=0;//implementazione diverse per teacher o student
    virtual User* clone() const=0;
    virtual ~User();


    bool operator == (const User& u) const;
    bool operator != (const User& u) const;
};

#endif // USER_H
