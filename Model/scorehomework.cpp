#include "scorehomework.h"





ScoreHomework::ScoreHomework(const string& t,const string& i,const string& a): Homework(t,i,a), total_score(0){
    for(MyVector<QuizContainer>::const_iterator it=container_q.begin(); it!=container_q.end(); ++it){
        total_score+=(*it).getTotalAllPoint();
    }
}


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

void ScoreHomework::addQuizContainer(const QuizContainer &q){
    Homework::addQuizContainer(q);

    addTotalScore(q.getTotalAllPoint());
}

void ScoreHomework::removeQuizContainer(const QuizContainer &q){
    Homework::removeQuizContainer(q);

    removeTotalScore(q.getTotalAllPoint());
}

double ScoreHomework::getResult() const{
    double somma=0;
    for(MyVector<QuizContainer>::const_iterator it=container_q.begin(); it!=container_q.end(); ++it){
        somma+=(*it).allPoint();
    }

    return somma/container_q.size();
}

ScoreHomework *ScoreHomework::clone() const{
    return new ScoreHomework(*this);
}

