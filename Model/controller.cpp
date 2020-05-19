#include "controller.h"

Controller::Controller(){
    Teacher* t= new Teacher("professor","professor");
    Student* s1= new Student("student1","student1");
    Student* s2= new Student("student2","student2");



    users.push_back(t);
    users.push_back(s1);
    users.push_back(s2);


    Course* z= new Course("Corso2","ciaooo");
    Course* y=new Course("Titolo","Descrizione");

    DateTime data(25,03,2020,00);

    y->addHomework(new TimeScoreHomework(data, "Prova compito"));
    z->addHomework(new ScoreHomework("Prova compito","istruzioni"));

    users[0]->addCourse(y);
    users[0]->addCourse(z);
    users[1]->addCourse(y);
    users[2]->addCourse(z);

}

Controller::~Controller(){
    for(unsigned int i=0;i<users.size();++i)
        delete users[i];
}

void Controller::deleteCourse(User* s,unsigned int index){

    for(unsigned int i=0;i<users.size();++i){

        if(s!=users[i]){

            for(unsigned int j=0;j<users[i]->getCourse().size();++j){
                if(users[i]->getCourse()[j]==s->getCourse()[index])
                    users[i]->deleteCourse(s->getCourse()[index]);

            }
        }

    }

    s->deleteCourse(s->getCourse()[index]);

}

void Controller::addCourse(User* s, std::string t, std::string d){
    s->addCourse(new Course(t,d));
}

User *Controller::getUser(const std::string &u, const std::string &p) const{
    for(MyVector<User*>::const_iterator it=users.begin(); it!=users.end();++it){
        if((*it)->getUsername()==u && (*it)->getPassword()==p){
            return *it;
        }
    }

    throw std::runtime_error("Username o password errati");
}


