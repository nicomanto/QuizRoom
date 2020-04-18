#include "quiz.h"

Quiz::Quiz(const std::string& q,int t, int pc, int m): question(q), total_point(t), point_correct_answer(pc), malus(m), my_point(0) {}

std::string Quiz::getQuestion() const{
    return question;
}

int Quiz::getTotalPoint() const{
    return total_point;
}

int Quiz::getPointAnswer() const{
    return point_correct_answer;
}

int Quiz::getMalus() const{
    return malus;
}

int Quiz::getMyPoint() const{
    return my_point;
}

void Quiz::setQuestion(const std::string& q){
    question=q;
}

void Quiz::setTotalPoint(int p){
    total_point=p;
}



Quiz::~Quiz(){}
