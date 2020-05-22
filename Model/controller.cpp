#include "controller.h"


Controller::Controller(){
    Teacher* t= new Teacher("professor","professor");
    Student* s1= new Student("student1","student1");
    Student* s2= new Student("student2","student2");



    users.push_back(t);
    users.push_back(s1);
    users.push_back(s2);


    Course* course_1= new Course("Titolo","Descrizione");
    Course* course_2 =new Course("Corso2","ciaooo");

    DateTime data(25,03,2020,00);

    Homework* homework_1= new TimeScoreHomework(data, "Prova compito");
    Homework* homework_2= new ScoreHomework("Prova compito 2","istruzioni");

    ClassicQuiz* quiz_1= new ClassicQuiz("Di che color è il cavallo bianco di napoleone?",100,0);
    quiz_1->addCorrectAnswer("Nero");
    quiz_1->addCorrectAnswer("Rosso");
    quiz_1->addCorrectAnswer("Bianco");
    quiz_1->addCorrectAnswer("Verde");

    CombineQuiz* quiz_2= new CombineQuiz("Abbina questi animali",100);
    quiz_2->addCorrectCombine("scimmia","mammifero");
    quiz_2->addCorrectCombine("cavallo","mammifero");
    quiz_2->addCorrectCombine("lucertola","rettile");
    quiz_2->addCorrectCombine("squalo","pesce");



    while(course_1->getCode()==course_2->getCode())
        course_2->setCode();

    homework_1->addQuiz(quiz_1);
    homework_1->addQuiz(quiz_1);

    homework_2->addQuiz(quiz_1);
    homework_2->addQuiz(quiz_2);


    course_1->addHomework(homework_1);
    course_2->addHomework(homework_2);



    users[0]->addCourse(course_1);
    users[0]->addCourse(course_2);
    users[1]->addCourse(course_1);
    users[2]->addCourse(course_2);

}

Controller::~Controller(){
    for(unsigned int i=0;i<users.size();++i)
        delete users[i];
}

void Controller::addStackView(PrincipalForm *p){
    stack_page.push_back(p);
}

PrincipalForm* Controller::removeStackView(){
    PrincipalForm* temp=stack_page.back();
    stack_page.pop_back();
    return temp;
}

void Controller::cleanStack(){
    stack_page.clear();
}

PrincipalForm *Controller::getPreviousPage(){
    return *(--stack_page.end());
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

void Controller::modifyHomework(Homework *h, const std::string &t, const std::string &d){
    h->setTitle(t);
    h->setInstructions(d);
}

void Controller::deleteHomework(Course *c, unsigned int i){
    c->removeHomework(c->getHomeworks()[i]);
}

void Controller::deleteHomework(Homework* h){
    for(unsigned int i=0;i<users.size();++i){
        for(unsigned int j=0;j<users[i]->getCourse().size();++j){
            for(unsigned int k=0;k<users[i]->getCourse()[j]->getHomeworks().size();++k)
                if(users[i]->getCourse()[j]->getHomeworks()[k]==h)
                    users[i]->getCourse()[j]->removeHomework(h);
        }


    }
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




