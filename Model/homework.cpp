#include "homework.h"

Homework::Homework(): done(false){}

Homework::Homework(const string& t, const string& i): title(t), instructions(i), done(false){}

string Homework::getTitle() const{
    return title;
}

std::string Homework::getInstructions() const
{
    return instructions;
}

const MyVector<Quiz*>& Homework::getQuiz() const{
    return quiz;
}

void Homework::setTitle(const string& t){
    title=t;
}

void Homework::setInstructions(const string& i){
    instructions=i;
}

void Homework::setDone(bool t){
    done=t;
}


bool Homework::isDone() const{
    return done;
}


void Homework::addQuiz(Quiz* q){
    quiz.push_back(q);
}

void Homework::removeQuiz(Quiz *q){
    MyVector<Quiz*>::iterator it=quiz.begin();
    bool temp=true;
    while(it!=quiz.end() && temp){

        if((*it)->getQuestion()==q->getQuestion())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        quiz.erase(it);


}




void Homework::showAllSolution() const{
    int i=1;
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        std::cout<<"Quiz "<<i<<std::endl;
        (*it)->showSolution();
        ++i;
    }
}

void Homework::showQuizSolution(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            (*it)->showSolution();

    }
}

double Homework::QuizPoint(const std::string &q) const{
    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        if((*it)->getQuestion()==q)
            return (*it)->CalcPointQuiz();

        }

    return 0;
}

double Homework::allPoint() const{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->CalcPointQuiz();
    }

    return somma;
}

double Homework::getTotalAllPoint() const
{
    double somma=0;

    for(MyVector<Quiz*>::const_iterator it=quiz.begin(); it!=quiz.end(); ++it){
        somma+=(*it)->getTotalPoint();
    }

    return somma;
}

bool Homework::isScoreHomework() const{
    return false;
}

bool Homework::isTimeHomework() const{
    return false;
}

double Homework::getResult() const{
    return 0;
}

Homework *Homework::clone() const{
    return new Homework(*this);
}

Homework::~Homework(){}
