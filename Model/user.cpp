#include "user.h"
User::User(const string& n, const string& s,const string& u,const string& p,const string& e): name(n), surname(s), username(u), password(p), email(e) {} //da aggiungere i corsi
string User::getName() const {return name;}
string User::getSurname() const {return surname;}
string User::getUsername() const {return username;}
string User::getPassword() const {return password;}
string User::getEmail() const {return email;}

MyVector<Course *> User::getCourse() const{
    //da implementare
}
//da aggiungere i corsi

void User::setName(const string& n) { name=n;}
void User::setSurname(const string& s) {surname=s;}
void User::setUsername(const string& u) {username=u;}
void User::setPassword(const string& p) {password=p;}
void User::setEmail(const string& e) {email=e;}

User::~User(){}

//da aggiungere i corsi

bool User::operator == (const User& u) const{ // da aggiunger il controllo sui corsi
    return name == u.name && surname==u.surname && username==u.username && password == u.password && email==u.email;
}

bool User::operator != (const User& u) const{ //da aggiungere il controllo sui corsi
    return !(*this==u);
}
