#include "controller.h"


Controller::Controller(){
    Teacher* t= new Teacher("professor","professor");
    Student* s1= new Student("student1","student1");
    Student* s2= new Student("student2","student2");


    users.push_back(t);
    users.push_back(s1);
    users.push_back(s2);

    Course* course_1 =new Course("Storia","Corso di storia della classe 2B");
    Course* course_2 =new Course("Matematica","Corso di matematica della classe 2B");

    while(course_1->getCode()==course_2->getCode())
        course_2->setCode();


    Course* course_3= new Course("Italiano","Corso di italiano della classe 2B, dove ogni settimana verranno caricati dei compiti con dei quiz da eseguire");

    while(course_1->getCode()==course_3->getCode() || course_2->getCode()==course_3->getCode())
        course_3->setCode();

    Course* course_4 =new Course("Scienze","Corso di scienze della classe 2B, dove ogni settimana verranno caricati dei compiti con dei quiz da eseguire");

    while(course_1->getCode()==course_4->getCode() || course_2->getCode()==course_4->getCode() || course_3->getCode()==course_4->getCode())
        course_4->setCode();

    DateTime data_1(25,03,2020,00);
    DateTime data_2(15,03,2021,00);


    Homework* homework_1= new TimeScoreHomework(data_2, "Antica Roma", "Questo breve quiz comprende alcune domande sull'Antica Roma. Ogni studente riceverà un voto "
                                                                     "che sarà pesato in base a quanto prima della fine della deadline è stato consegnato");
    Homework* homework_2= new ScoreHomework("Equazioni","Questo quiz mettrà alla prova le vostre abilità sulle equazioni, divertitevi :)");

    Homework* homework_3= new TimeScoreHomework(data_1,"Grammatica","Rispondi alle domande riguardo la grammatica italiana");

    Homework* homework_4= new Homework("Famiglie di animali","Compito che si concentrerà sul rispondere ad alcune domande riguardo alla classificazione degli animali");

    ClassicQuiz* quiz_1= new ClassicQuiz("Di che color è il cavallo bianco di Nerone?");
    quiz_1->addAnswer("Nero");
    quiz_1->addAnswer("Rosso");
    quiz_1->addCorrectAnswer("Bianco");
    quiz_1->addAnswer("Verde");

    ClassicQuiz* quiz_2= new ClassicQuiz("Secondo la mitologia, chi fu il primo Re di Roma?");
    quiz_2->addAnswer("Giulio Cesare");
    quiz_2->addAnswer("Totti");
    quiz_2->addCorrectAnswer("Romolo");
    quiz_2->addAnswer("Remo");


    ClassicQuiz* quiz_3= new ClassicQuiz("La caduta dell'Impero romano d'Occidente è fissata a...");
    quiz_3->addAnswer("2020 d. C.");
    quiz_3->addAnswer("0 d. C.");
    quiz_3->addCorrectAnswer("476 d. C.");
    quiz_3->addAnswer("1492 d. C.");

    CombineQuiz* quiz_4= new CombineQuiz("In che anno sono stati proclamati Imperatori?");
    quiz_4->addCorrectCombine("Giulio Cesare","49 a. C.");
    quiz_4->addCorrectCombine("Nerone","54 d. C.");
    quiz_4->addCorrectCombine("Caligola","37 d. C.");
    quiz_4->addCorrectCombine("Marco Aurelio","180 d. C.");

    ClassicQuiz* quiz_5= new ClassicQuiz("Chi è famoso per aver bruciato Roma?");
    quiz_5->addAnswer("Totti");
    quiz_5->addAnswer("Augusto");
    quiz_5->addCorrectAnswer("Nerone");
    quiz_5->addAnswer("Romolo Augustolo");







    ClassicQuiz* quiz_6= new ClassicQuiz("Quanto fa x = 5+5*0?");
    quiz_6->addCorrectAnswer("x = 5");
    quiz_6->addCorrectAnswer("x = 10-5");
    quiz_6->addAnswer("x = 22");
    quiz_6->addAnswer("x = 0");


    ClassicQuiz* quiz_7= new ClassicQuiz("Quanto fa x^2 = 49?");
    quiz_7->addAnswer("x = -7");
    quiz_7->addAnswer("x = +7");
    quiz_7->addCorrectAnswer("x1 = -7, x2 = +7");
    quiz_7->addAnswer("x = 49");


    ClassicQuiz* quiz_8= new ClassicQuiz("Quanto fa x+3+7=0?");
    quiz_8->addCorrectAnswer("x=-10");
    quiz_8->addAnswer("x=10");
    quiz_8->addAnswer("x=-4");
    quiz_8->addAnswer("x=4");


    CombineQuiz* quiz_9= new CombineQuiz("Abbina l'equazione alla risposta esatta");
    quiz_9->addCorrectCombine("x = 9","9");
    quiz_9->addCorrectCombine("x+2-4 = 7","9");
    quiz_9->addCorrectCombine("-2y = -4","2");
    quiz_9->addCorrectCombine("0x = 7","impossiile");








    ClassicQuiz* quiz_10= new ClassicQuiz("Quali di questi è un articolo?");
    quiz_10->addCorrectAnswer("la");
    quiz_10->addCorrectAnswer("il");
    quiz_10->addCorrectAnswer("un");
    quiz_10->addAnswer("tra");


    CombineQuiz* quiz_11= new CombineQuiz("Abbina alla descrizione più appropriata");
    quiz_11->addCorrectCombine("la","articolo");
    quiz_11->addCorrectCombine("Claudio","nome");
    quiz_11->addCorrectCombine("bello","aggettivo");
    quiz_11->addCorrectCombine("di","preposizione");

    CombineQuiz* quiz_12= new CombineQuiz("Abbina alla descrizione più appropriata");
    quiz_12->addCorrectCombine("io","pronome");
    quiz_12->addCorrectCombine("tu","pronome");
    quiz_12->addCorrectCombine("simpatico","aggettivo");
    quiz_12->addCorrectCombine("andare","verbo");


    CombineQuiz* quiz_13= new CombineQuiz("Nome proprio o nome comune?");
    quiz_13->addCorrectCombine("cane","nome comune");
    quiz_13->addCorrectCombine("Roberto","nome proprio");
    quiz_13->addCorrectCombine("Briciola","nome proprio");
    quiz_13->addCorrectCombine("uomo","nome comune");








    CombineQuiz* quiz_14= new CombineQuiz("A quale classe appartiene ciascun animale?");
    quiz_14->addCorrectCombine("scimmia","mammifero");
    quiz_14->addCorrectCombine("cavallo","mammifero");
    quiz_14->addCorrectCombine("lucertola","rettile");
    quiz_14->addCorrectCombine("squalo","pesce");

    ClassicQuiz* quiz_15= new ClassicQuiz("Quale classe depone le uova?");
    quiz_15->addCorrectAnswer("Rettili");
    quiz_15->addAnswer("Mammiferi");
    quiz_15->addCorrectAnswer("Uccelli");
    quiz_15->addCorrectAnswer("Pesci");

    ClassicQuiz* quiz_16= new ClassicQuiz("Questi animali depongono le uova, trova l'intruso");
    quiz_16->addCorrectAnswer("Delfino");
    quiz_16->addAnswer("Pinguino");
    quiz_16->addAnswer("Squalo");
    quiz_16->addAnswer("Serpente");

    ClassicQuiz* quiz_17= new ClassicQuiz("Tutti questi animali sono mammiferi, seleziona la risposta sbagliata");
    quiz_17->addAnswer("delfino");
    quiz_17->addCorrectAnswer("squalo");
    quiz_17->addAnswer("maiale");
    quiz_17->addAnswer("orso");

    CombineQuiz* quiz_18= new CombineQuiz("A quale classe appartiene ciascun animale?");
    quiz_18->addCorrectCombine("umano","mammifero");
    quiz_18->addCorrectCombine("rondine","uccello");
    quiz_18->addCorrectCombine("serpente","rettile");
    quiz_18->addCorrectCombine("cavalletta","insetto");

    homework_1->addQuiz(quiz_1);
    homework_1->addQuiz(quiz_2);
    homework_1->addQuiz(quiz_3);
    homework_1->addQuiz(quiz_4);
    homework_1->addQuiz(quiz_5);


    homework_2->addQuiz(quiz_6);
    homework_2->addQuiz(quiz_7);
    homework_2->addQuiz(quiz_8);
    homework_2->addQuiz(quiz_9);



    homework_3->addQuiz(quiz_10);
    homework_3->addQuiz(quiz_11);
    homework_3->addQuiz(quiz_12);
    homework_3->addQuiz(quiz_13);

    homework_4->addQuiz(quiz_14);
    homework_4->addQuiz(quiz_15);
    homework_4->addQuiz(quiz_16);
    homework_4->addQuiz(quiz_17);
    homework_4->addQuiz(quiz_18);


    course_1->addHomework(homework_1);
    course_2->addHomework(homework_2);
    course_3->addHomework(homework_3);
    course_4->addHomework(homework_4);





    users[0]->addCourse(course_1);
    users[0]->addCourse(course_2);
    users[0]->addCourse(course_3);
    users[0]->addCourse(course_4);

    users[1]->addCourse(course_1);
    users[1]->addCourse(course_3);
    users[2]->addCourse(course_2);
    users[2]->addCourse(course_4);

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

    for(unsigned int i=0;i<s->getCourse().size();++i)
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










