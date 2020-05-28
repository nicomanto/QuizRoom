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

    ClassicQuiz* quiz_1= new ClassicQuiz("Di che color è il cavallo bianco di napoleone?");
    quiz_1->addAnswer("Nero");
    quiz_1->addAnswer("Rosso");
    quiz_1->addCorrectAnswer("Bianco");
    quiz_1->addAnswer("Verde");

    CombineQuiz* quiz_2= new CombineQuiz("Abbina questi animali");
    quiz_2->addCorrectCombine("scimmia","mammifero");
    quiz_2->addCorrectCombine("cavallo","mammifero");
    quiz_2->addCorrectCombine("lucertola","rettile");
    quiz_2->addCorrectCombine("squalo","pesce");

    ClassicQuiz* quiz_3= new ClassicQuiz("Di che color è il cavallo nero di napoleone?");
    quiz_3->addCorrectAnswer("Nero");
    quiz_3->addAnswer("Rosso");
    quiz_3->addAnswer("Bianco");
    quiz_3->addAnswer("Verde");

    ClassicQuiz* quiz_4= new ClassicQuiz("Quando è stata scoperta l'america?");
    quiz_4->addCorrectAnswer("1492");
    quiz_4->addAnswer("2020");
    quiz_4->addAnswer("10 A.C.");
    quiz_4->addAnswer("1999");

    ClassicQuiz* quiz_5= new ClassicQuiz("Quanto fa 5+5*0");
    quiz_5->addCorrectAnswer("5");
    quiz_5->addCorrectAnswer("10-5");
    quiz_5->addAnswer("22");
    quiz_5->addAnswer("0");

    CombineQuiz* quiz_6 =new CombineQuiz("Chi è la versione femminile? Abbina");
    quiz_6->addCorrectCombine("Leone","Leonessa");
    quiz_6->addCorrectCombine("Toro","Mucca");
    quiz_6->addCorrectCombine("Gallo","Gallina");
    quiz_6->addCorrectCombine("Cane","Cagnolina");



    while(course_1->getCode()==course_2->getCode())
        course_2->setCode();

    homework_1->addQuiz(quiz_1);
    homework_1->addQuiz(quiz_2);
    homework_1->addQuiz(quiz_3);
    homework_1->addQuiz(quiz_4);
    homework_1->addQuiz(quiz_5);
    homework_1->addQuiz(quiz_6);

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



User *Controller::getUser(const std::string &u, const std::string &p) const{
    for(MyVector<User*>::const_iterator it=users.begin(); it!=users.end();++it){
        if((*it)->getUsername()==u && (*it)->getPassword()==p){
            return *it;
        }
    }

    throw std::logic_error("Username o password errati");
}

unsigned int Controller::getNumberUserCourse(User *u) const{
    return u->getCourse().size();
}

bool Controller::UserCanAddCourse(User *u) const{
    return u->CanAddCourse();
}

bool Controller::UserCanAddQuiz(User *u) const{
    return u->CanAddQuiz();
}

bool Controller::UserCanAddHomework(User *u) const{
    return u->CanAddHomework();
}

bool Controller::UserCanDeleteHomework(User *u) const{
    return u->CanDeleteHomework();
}

bool Controller::UserCanDeleteCourse(User *u) const{
    return u->CanDeleteCourse();
}

bool Controller::UserCanEditCourse(User *u) const{
    return u->CanEditCourse();
}

bool Controller::UserCanEditHomework(User *u) const{
    return u->CanEditHomework();
}



void Controller::addCourseFromCode(User *s, const std::string &code){
    bool find=false;

    for(unsigned int i=0;i<s->getCourse().size(); ++i){
        if(s->getCourse()[i]->getCode()==code)
            throw std::logic_error("Sei già iscritto a questo corso");
    }

    for(unsigned int i=0;i<users.size() && !find;++i){
        for(unsigned int j=0;j<users[i]->getCourse().size() && !find;++j){
                if(users[i]->getCourse()[j]->getCode()==code){
                    s->addCourse(users[i]->getCourse()[j]);
                    find=true;
                }
        }


    }

    if(!find)
        throw std::logic_error("Corso "+code+" non presente");
}

void Controller::modifyCourse(Course *c, const string& t, const string& d){
    if(t=="")
         throw std::logic_error("Titolo mancante");

    c->setTitle(t);
    c->setDescription(d);
}

void Controller::addCourse(User* s, const string& t, const string& d){
    if(t=="")
        throw std::logic_error("Titolo mancante");

    Course* temp=new Course(t,d);

    for(int i=0;i<s->getCourse().size();++i)
        if(s->getCourse()[i]->getCode()==temp->getCode())
            temp->setCode();

    s->addCourse(new Course(t,d));
}

Course *Controller::getCourse(User *u, unsigned int i) const{
    return u->getCourse()[i];
}

unsigned int Controller::getNumberCourseHomework(Course *c) const{
    return c->getHomeworks().size();
}

const std::string &Controller::getCourseTitle(Course *c) const{
    return c->getTitle();
}

const std::string &Controller::getCourseDescription(Course *c) const{
    return c->getDescription();
}

const std::string &Controller::getCourseCode(Course *c) const{
    return c->getCode();
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

Homework *Controller::getHomework(Course *c, unsigned int i) const{
    return c->getHomeworks()[i];
}

void Controller::AddHomework(Course* c, const std::string &t, const std::string &d, bool time, bool score, const DateTime &deadline){
    if(t=="")
         throw std::logic_error("Titolo mancante");

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
    if(t=="")
         throw std::logic_error("Titolo mancante");

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

const std::string &Controller::getHomeworkTitle(Homework *h) const{
    return h->getTitle();
}

const std::string &Controller::getHomeworkInstructions(Homework *h) const{
    return h->getInstructions();
}

bool Controller::isTimeHomework(Homework *h) const{
    return h->isTimeHomework();
}

bool Controller::isScoreHomework(Homework *h) const{
    return h->isScoreHomework();
}

bool Controller::haveEmptyQuiz(Homework *h) const{
    return h->getQuiz().empty();
}

unsigned int Controller::getNumberHomeworkQuiz(Homework *h) const{
    return h->getQuiz().size();
}

const std::string Controller::SolutionHomeworkToString(Homework *h) const{
    return h->AllSolutionToString();
}

double Controller::getResultHomework(Homework *h) const{
    return h->getResult();
}

void Controller::resetHomeworkQuizPoint(Homework* h){
    h->resetPointQuiz();
}

bool Controller::HomeworkHaveResult(Homework *h) const{
return h->haveResult();
}

void Controller::HomeworkClearQuiz(Homework *h){
    h->clearQuiz();
}

void Controller::addCombineQuiz(Homework *h, const std::string &question, const MyVector<std::string> &elements, const MyVector<std::string> &answers){
    if(question=="")
        throw std::logic_error("Domanda mancante");

    for(unsigned int i=0; i<elements.size();++i){
        if(elements[i]=="") throw std::logic_error("Elemento da abbinare mancante");
        if(answers[i]=="") throw std::logic_error("Risposta da abbinare mancante");
    }

    for(unsigned int i=0; i<elements.size()-1;++i){
        for(unsigned int j=i+1; j<elements.size();++j){
            if(elements[i]==elements[j])
                throw std::logic_error("Le opzioni da abbinare non possono essere uguali fra di loro");
        }

    }




    /*bool not_exist=true;

    //controllo se esiste un quiz con la domanda uguale e lo aggiorno
    for(unsigned int i=0;i <h->getQuiz().size() && not_exist;++i){
        if(dynamic_cast<CombineQuiz*>(h->getQuiz()[i])){
            CombineQuiz* temp= dynamic_cast<CombineQuiz*>(h->getQuiz()[i]);

            if(temp->getQuestion()==question){

                temp->clear_all_answers();
                not_exist=false;






            }
        }


    }*/



        CombineQuiz* quiz= new CombineQuiz(question);

        for(unsigned int i=0; i<elements.size();++i){
            //std::cout<<correct_answers[i]<<std::endl;
            quiz->addCorrectCombine(elements[i],answers[i]);
        }

        h->addQuiz(quiz);

}

void Controller::addClassicQuiz(Homework *h, const std::string &question, const MyVector<std::string>& answers, const MyVector<std::string>& correct_answers){
    if(question=="")
            throw std::logic_error("Domanda mancante");


    for(unsigned int i=0; i<answers.size();++i){
        if(answers[i]=="") throw std::logic_error("Risposta mancante");
    }



    if(correct_answers.empty()){
        throw std::logic_error("Aggiungi almeno una risposta corretta");
    }





    for(unsigned int i=0; i<answers.size()-1;++i){
        for(unsigned int j=i+1; j<answers.size();++j){
            if(answers[i]==answers[j])
                throw std::logic_error("Le riposte devono essere diverse fra di loro");
        }

    }

    /*bool not_exist=true;

    //controllo se esiste un quiz con la domanda uguale e lo aggiorno
    for(unsigned int i=0;i <h->getQuiz().size() && not_exist;++i){
        if(dynamic_cast<ClassicQuiz*>(h->getQuiz()[i])){
            ClassicQuiz* temp= dynamic_cast<ClassicQuiz*>(h->getQuiz()[i]);

            if(temp->getQuestion()==question){

                temp->clear_all_answers();
                not_exist=false;



                for(unsigned int i=0; i<answers.size();++i){
                    //std::cout<<correct_answers[i]<<std::endl;
                    temp->addAnswer(answers[i]);
                }

                for(unsigned int i=0; i<correct_answers.size();++i){
                    //std::cout<<correct_answers[i]<<std::endl;
                    temp->addCorrectAnswer(correct_answers[i]);
                }
            }
        }


    }*/



        ClassicQuiz* quiz= new ClassicQuiz(question);

        //std::cout<<"size answer: "<<answers.size()<<std::endl;
        for(unsigned int i=0; i<answers.size();++i){
            //std::cout<<correct_answers[i]<<std::endl;
            quiz->addAnswer(answers[i]);
        }

        for(unsigned int i=0; i<correct_answers.size();++i){
            //std::cout<<correct_answers[i]<<std::endl;
            quiz->addCorrectAnswer(correct_answers[i]);
        }

        h->addQuiz(quiz);

}

/*void Controller::addPoint(Homework *k,){
}*/




Quiz *Controller::getQuiz(Homework *h, unsigned int i) const{
    return h->getQuiz()[i];
}

const std::map<std::string, std::string> &Controller::getCorrectAnswersCombineQuiz(CombineQuiz* quiz) const{
    return quiz->getCorrectAnswer();
}

unsigned int Controller::getCorrectAnswersCombineQuizSize(CombineQuiz* quiz) const{
    return quiz->getCorrectAnswer().size();
}

void Controller::addPointCombineQuiz(CombineQuiz *quiz,const string& option,const string& answer){
    quiz->addPoint(option,answer);
}

const MyVector<std::string> &Controller::getAnswersClassicQuiz(ClassicQuiz *quiz) const{
    return quiz->getAnswers();
}

unsigned int Controller::getAnswersClassicQuizSize(ClassicQuiz *quiz) const{
    return quiz->getAnswers().size();
}

const std::string &Controller::getAnsweratIndexClassicQuiz(ClassicQuiz *quiz, unsigned int index) const{
    return quiz->getAnswers()[index];
}

void Controller::addPointClassicQuiz(ClassicQuiz *quiz, const std::string &answer){
    quiz->addPoint(answer);
}










