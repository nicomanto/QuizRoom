#include "vectorusers.h"

VectorUsers::VectorUsers(){
    users.push_back(new Teacher("professor","professor"));
    users.push_back(new Student ("student1","student1"));
    users.push_back(new Student ("student2","student2"));

    Course y("Titolo","Descrizione");
    Course z("Corso2","ciaooo");

    DateTime data(25,03,2020,00);

    y.addHomework(new TimeScoreHomework(data, "Prova compito"));
    z.addHomework(new ScoreHomework("Prova compito","istruzioni"));

    users[0]->addCourse(y);
    users[0]->addCourse(z);
    users[1]->addCourse(y);
    users[2]->addCourse(y);
}

VectorUsers::~VectorUsers(){
    for(unsigned int i=0;i<users.size();++i)
        delete users[i];
}

User *VectorUsers::getUser(const std::string &u, const std::string &p) const{
    for(MyVector<User*>::const_iterator it=users.begin(); it!=users.end();++it){
        if((*it)->getUsername()==u && (*it)->getPassword()==p){
            return *it;
        }
    }

    throw std::runtime_error("Username o password errati");
}
