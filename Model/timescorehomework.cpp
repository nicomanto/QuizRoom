#include "timescorehomework.h"

TimeScoreHomework::TimeScoreHomework(){}

TimeScoreHomework::TimeScoreHomework(const DateTime& d,const string& t,const string& i) : Homework(t,i) , TimeHomework(d,t,i), ScoreHomework(t,i){}

bool TimeScoreHomework::isScoreHomework() const{
    return true;
}

bool TimeScoreHomework::isTimeHomework() const{
    return true;
}

bool TimeScoreHomework::haveResult() const{
    return true;
}

double TimeScoreHomework::getResult() const{
    double somma=ScoreHomework::getResult();
    DateTime now(DateTime::getCurrentDateTime());

    if(now>deadline){

        if(now.Year()>deadline.Year() || (now.Year()==deadline.Year() && now.Month()>deadline.Month()))
                somma-=3;
        else{

            if((static_cast<int>(now.Day())-static_cast<int>(deadline.Day()))>day_max_malus || (static_cast<int>(now.Day())-static_cast<int>(deadline.Day()))==day_max_malus && now.Time::operator>(deadline))
                somma-=3;
            else if((static_cast<int>(now.Day())-static_cast<int>(deadline.Day()))>(day_max_malus-1) || ((static_cast<int>(now.Day())-static_cast<int>(deadline.Day()))==(day_max_malus-1)) && now.Time::operator>(deadline))
                somma-=2;
            else
                somma-=1;
           }
        }

    return somma;

}

TimeScoreHomework *TimeScoreHomework::clone() const{
    return new TimeScoreHomework(*this);
}


int TimeScoreHomework::day_max_malus=2;
