#include "vectorusers.h"

VectorUsers::VectorUsers(){
    Teacher p("professor","professor");
    Student s1("student1","student1");
    Student s2("student2","student2");

    users.push_back(new Teacher("professor","professor"));
    users.push_back(new Student ("student1","student1"));
    users.push_back(new Student ("student2","student2"));

    Course y("Titolo","Descrizione");
    Course z("Corso2","ciaooo");
    users[0]->addCourse(y);
    users[0]->addCourse(z);
    users[1]->addCourse(y);
    users[2]->addCourse(y);
}

User *VectorUsers::getUser(const std::string &u, const std::string &p) const{
    for(MyVector<User*>::const_iterator it=users.begin(); it!=users.end();++it){
        if((*it)->getUsername()==u && (*it)->getPassword()==p){
            return *it;
        }
    }

    throw std::runtime_error("Username o password errati");
}
