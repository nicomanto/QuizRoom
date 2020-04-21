#include "quizcontainer.h"

QuizContainer::QuizContainer(){}

QuizContainer::QuizContainer(const std::string& t, const std::string &d): title(t), description(d){}


std::string QuizContainer::getTitle() const{
    return title;
}


std::string QuizContainer::getDescription() const{
    return description;
}

const MyVector<Quiz *> &QuizContainer::getQuiz() const{
    return quiz;
}

void QuizContainer::setTitle(const std::string &t){
    title=t;
}

void QuizContainer::setDescription(const std::string &d){
    description=d;
}


void QuizContainer::addQuiz(Quiz* q){
    quiz.push_back(q);
}

void QuizContainer::removeQuiz(Quiz *q){
    /*MyVector<Quiz*>::iterator it=quiz.begin();
    bool temp=true;
    while(it!=quiz.end() && temp){

        if((*it)->getQuestion()==q->getQuestion())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        quiz.erase(it);

    */
}

void QuizContainer::showAllSolution() const{
    int i=1;
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        std::cout<<"Quiz "<<i<<std::endl;
        (*it)->showSolution();
        ++i;
    }
}

void QuizContainer::showQuizSolution(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            (*it)->showSolution();

    }
}

double QuizContainer::QuizPoint(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            return (*it)->CalcPointQuiz();

        }

    return 0;
}

double QuizContainer::allPoint() const{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->CalcPointQuiz();
    }

    return somma;
}

double QuizContainer::getTotalAllPoint() const
{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->getTotalPoint();
    }

    return somma;
}

/*QuizContainer::~QuizContainer(){
    for(MyVector<Quiz*>::iterator it=quiz.begin(); it!=quiz.end(); ++it){
        delete (*it);
    }
}*/
