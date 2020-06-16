#include "quiz.h"


Quiz::Quiz():question(std::string()), point_correct_answer(0), my_point(0){}

Quiz::Quiz(const std::string& q): question(q), point_correct_answer(0), my_point(0){}

const std::string& Quiz::getQuestion() const{
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

void Quiz::addMyPoint(double p){
    my_point+=p;
}


Quiz::~Quiz(){}


double Quiz::total_point=10;
