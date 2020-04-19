#include "quiz.h"

Quiz::Quiz(const std::string& q,double t): question(q), total_point(t), point_correct_answer(0), my_point(0) {}

std::string Quiz::getQuestion() const{
    return question;
}

double Quiz::getTotalPoint() const{
    return total_point;
}

double Quiz::getPointAnswer() const{
    return point_correct_answer;
}

double Quiz::getMyPoint() const{
    return my_point;
}

void Quiz::setQuestion(const std::string& q){
    question=q;
}

void Quiz::setTotalPoint(int p){
    total_point=p;
}

void Quiz::addMyPoint(double p){
    my_point+=p;
}

void Quiz::addPointCorrectAnswer(double m){
    point_correct_answer+=m;
}


Quiz::~Quiz(){}
