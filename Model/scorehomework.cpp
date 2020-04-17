#include "scorehomework.h"



ScoreHomework::ScoreHomework(int ts,const string& t,const string& i,const string& a): Homework(t,i,a), total_score(ts){}

int ScoreHomework::getScore() const{
    return total_score;
}

int ScoreHomework::getResult() const
{
    //da implementare

    //penso un semplice calcolo dei punti per ogni quiz.
}

ScoreHomework *ScoreHomework::clone() const{
    return new ScoreHomework(*this);
}




void ScoreHomework::setScore(int ts){
    total_score=ts;
}
