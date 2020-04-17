#include "timescorehomework.h"

TimeScoreHomework::TimeScoreHomework(const DateTime& d, int ts,const string& t,const string& i,const string& a) : Homework(t,i,a) , TimeHomework(d,t,i,a), ScoreHomework(ts,t,i,a){}

int TimeScoreHomework::getResult() const
{
    //da implementare
}

TimeScoreHomework *TimeScoreHomework::clone() const{
    return new TimeScoreHomework(*this);
}
