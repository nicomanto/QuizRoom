#include "timehomework.h"

TimeHomework::TimeHomework(){}

TimeHomework::TimeHomework(const DateTime& d,const std::string& t,const std::string& i): Homework(t,i), deadline(d){}

void TimeHomework::setDeadline(const DateTime &d){
    deadline=d;
}

const DateTime& TimeHomework::getDeadline() const{
    return deadline;
}

bool TimeHomework::isScoreHomework() const{
    return false;
}

bool TimeHomework::isTimeHomework() const{
    return true;
}

bool TimeHomework::haveResult() const{
    return true;
}

double TimeHomework::getResult() const{
    return deadline.daysFromNowToDate();
}

TimeHomework *TimeHomework::clone() const{
    return new TimeHomework(*this);
}
