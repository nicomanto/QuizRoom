#include "scorehomework.h"

ScoreHomework::ScoreHomework(){}

ScoreHomework::ScoreHomework(const string& t,const string& i): Homework(t,i){}

bool ScoreHomework::isScoreHomework() const{
    return true;
}

bool ScoreHomework::isTimeHomework() const{
    return false;
}

bool ScoreHomework::haveResult() const{
    return true;
}

double ScoreHomework::getResult() const{
    double somma=allPoint();

    return somma/quiz.size();
}

ScoreHomework *ScoreHomework::clone() const{
    return new ScoreHomework(*this);
}

