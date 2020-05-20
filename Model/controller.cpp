#include "controller.h"


Controller::Controller(){
    Teacher* t= new Teacher("professor","professor");
    Student* s1= new Student("student1","student1");
    Student* s2= new Student("student2","student2");



    users.push_back(t);
    users.push_back(s1);
    users.push_back(s2);


    Course* z= new Course("Corso2","ciaooo");
    Course* y   =new Course("Titolo","Descrizione");

    while(z->getCode()==y->getCode())
        y->setCode();
    DateTime data(25,03,2020,00);

    y->addHomework(new TimeScoreHomework(data, "Prova compito"));
    z->addHomework(new ScoreHomework("Prova compito 2","istruzioni"));



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

void Controller::deleteCourse(Course* c){

    for(unsigned int i=0;i<users.size();++i){
        for(unsigned int j=0;j<users[i]->getCourse().size();++j){
                if(users[i]->getCourse()[j]==c)
                    users[i]->deleteCourse(c);
        }


    }



}

void Controller::AddHomework(Course* c, const std::string &t, const std::string &d, bool time, bool score, const DateTime &deadline){
    Homework* temp;
    if(time && score)
        temp = new TimeScoreHomework(deadline,t,d);

    else if(time)
        temp = new TimeHomework(deadline,t,d);

    else if(score)
        temp= new ScoreHomework(t,d);

    else
        temp= new Homework(t,d);


    c->addHomework(temp);

}

void Controller::deleteHomework(Course *c, unsigned int i){
    c->removeHomework(c->getHomeworks()[i]);
}

void Controller::modifyCourse(Course *c, const string& t, const string& d){
    c->setTitle(t);
    c->setDescription(d);
}

void Controller::addCourse(User* s, const string& t, const string& d){
    Course* temp=new Course(t,d);

    for(int i=0;i<s->getCourse().size();++i)
        if(s->getCourse()[i]->getCode()==temp->getCode())
            temp->setCode();

    s->addCourse(new Course(t,d));
}

User *Controller::getUser(const std::string &u, const std::string &p) const{
    for(MyVector<User*>::const_iterator it=users.begin(); it!=users.end();++it){
        if((*it)->getUsername()==u && (*it)->getPassword()==p){
            return *it;
        }
    }

    throw std::logic_error("Username o password errati");
}




