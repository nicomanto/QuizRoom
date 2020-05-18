#include "timehomework.h"

TimeHomework::TimeHomework(){}

TimeHomework::TimeHomework(const DateTime& d,const std::string& t,const std::string& i): Homework(t,i), deadline(d){}

void TimeHomework::setDeadline(const DateTime &d){
    deadline=d;
}

DateTime TimeHomework::getDeadline() const{
    return deadline;
}

bool TimeHomework::isScoreHomework() const{
    return false;
}

bool TimeHomework::isTimeHomework() const{
    return true;
}

double TimeHomework::getResult() const{
    DateTime now(DateTime::getCurrentDateTime());

    if(now<deadline || now==deadline)
        return true;

    else
        return false;
}

TimeHomework *TimeHomework::clone() const{
    return new TimeHomework(*this);
}
