#include "homework.h"

Homework::Homework(){}

Homework::Homework(const string& t, const string& i,const string& a): title(t), instructions(i), arguments(a){}

string Homework::getTitle() const{
    return title;
}

std::string Homework::getInstructions() const
{
    return instructions;
}

string Homework::getArguments() const{
    return arguments;
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

void Homework::setArguments(const string& a){
    arguments=a;
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

Homework::~Homework(){}
