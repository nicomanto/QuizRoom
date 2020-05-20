#include "homework.h"

Homework::Homework(){}

Homework::Homework(const string& t, const string& i): title(t), instructions(i){}

string Homework::getTitle() const{
    return title;
}

std::string Homework::getInstructions() const
{
    return instructions;
}

const MyVector<QuizContainer>& Homework::getContainerQuiz() const{
    return container_q;
}

void Homework::setTitle(const string& t){
    title=t;
}

void Homework::setInstructions(const string& i){
    instructions=i;
}


bool Homework::isDone() const{
    bool temp=true;
    for(MyVector<QuizContainer>::const_iterator it=container_q.begin(); it!=container_q.end() && temp; ++it)
        if(!(it->isDone()))
            temp=false;

    return temp;
}

void Homework::addQuizContainer(const QuizContainer &q){
    container_q.push_back(q);
}

void Homework::removeQuizContainer(const QuizContainer &q){

    MyVector<QuizContainer>::iterator it=container_q.begin();
    bool temp=true;
    while(it!=container_q.end() && temp){
          if(it->getTitle()==q.getTitle())
            temp = false;
          else
            ++it;
    }

    if(!temp)
        container_q.erase(it);


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
