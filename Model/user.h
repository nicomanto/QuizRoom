#ifndef USER_H
#define USER_H
#include <string>

#include "myvector.h"
#include "course.h"

class Course;
using std::string;

class User {
protected:
    string username;
    string password;
    MyVector<Course*> course; // da mettere dopo che è stata creata l'opportuna classe;
public:
    User();
    User(const string& u,const string& p);

    string getUsername() const;
    string getPassword() const;
    const MyVector<Course*>& getCourse() const;

    void setUsername(const string& u);
    void setPassword(const string& p);

    virtual bool CanAddCourse()const =0;
    virtual void addCourse(Course* c);
    virtual bool CanDeleteCourse() const=0;
    virtual void deleteCourse(Course* c);
    virtual bool CanEditCourse() const=0;

    virtual bool CanAddHomework()const =0;
    virtual bool CanDeleteHomework() const=0;
    virtual bool CanEditHomework() const=0;

    virtual bool CanAddQuiz() const=0;
    virtual bool CanDeleteQuiz() const=0;
    virtual bool CanEditQuiz() const=0;
    //virtual bool CanDoQuiz() const=0;


    virtual User* clone() const=0;
    virtual ~User();


    bool operator == (const User& u) const;
    bool operator != (const User& u) const;
};

#endif // USER_H
