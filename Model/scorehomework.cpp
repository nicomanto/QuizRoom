#include "scorehomework.h"

ScoreHomework::ScoreHomework(){}

ScoreHomework::ScoreHomework(const string& t,const string& i): Homework(t,i), total_score(getTotalAllPoint()){}


void ScoreHomework::addTotalScore(double p){
    total_score+=p;
}

void ScoreHomework::removeTotalScore(double p){
    total_score-=p;
}



double ScoreHomework::getTotalScore() const{
    return total_score;
}


bool ScoreHomework::isScoreHomework() const{
    return true;
}

bool ScoreHomework::isTimeHomework() const{
    return false;
}

void ScoreHomework::addQuiz(Quiz* q){
    Homework::addQuiz(q);

    addTotalScore(getTotalAllPoint());
}

void ScoreHomework::removeQuiz(Quiz* q){
    Homework::removeQuiz(q);

    removeTotalScore(getTotalAllPoint());
}

double ScoreHomework::getResult() const{
    double somma=allPoint();

    return somma/quiz.size();
}

ScoreHomework *ScoreHomework::clone() const{
    return new ScoreHomework(*this);
}

