#include "user.h"
User::User(){}

User::User(const string& u,const string& p): username(u), password(p){}
string User::getUsername() const {return username;}
string User::getPassword() const {return password;}

const MyVector<Course*>& User::getCourse() const{
    return course;
}

void User::setUsername(const string& u) {username=u;}
void User::setPassword(const string& p) {password=p;}

void User::addCourse(Course* c){
    course.push_back(c);
}

void User::deleteCourse(Course* c){
    MyVector<Course*>::iterator it=course.begin();
    bool temp=true;
    while(it!=course.end() && temp){
          if((*it)->getTitle()==c->getTitle())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        course.erase(it);


}

User::~User(){}


bool User::operator == (const User& u) const{
    return username==u.username && password == u.password;
}

bool User::operator != (const User& u) const{
    return !(*this==u);
}
