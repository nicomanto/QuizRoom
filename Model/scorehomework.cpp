#include "scorehomework.h"



ScoreHomework::ScoreHomework(string t, string i,string a): Homework(t,i,a), score(calc_score()){}

int ScoreHomework::getScore() const{
    return score;
}

int ScoreHomework::calc_score()
{
    //da implementare
}

int ScoreHomework::setScore(){
    score=calc_score();
}
