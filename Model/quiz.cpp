#include "quiz.h"

Quiz::Quiz(const std::string& q,int p): question(q), point(p) {}

std::string Quiz::getQuestion() const{
    return question;
}

int Quiz::getPoint() const{
    return point;
}

void Quiz::setQuestion(const std::string& q){
    question=q;
}

void Quiz::setPoint(int p){
    point=p;
}

Quiz::~Quiz(){

}
