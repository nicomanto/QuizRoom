#include "timescorehomework.h"

TimeScoreHomework::TimeScoreHomework(const DateTime& d, int ts, string t, string i,string a) : Homework(t,i,a) , TimeHomework(d,t,i,a), ScoreHomework(ts,t,i,a){}

int TimeScoreHomework::getResult() const
{
    //da implementare
}

TimeScoreHomework *TimeScoreHomework::clone() const{
    return new TimeScoreHomework(*this);
}
