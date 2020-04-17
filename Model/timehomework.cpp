#include "timehomework.h"

void TimeHomework::setDeadline(const DateTime &d){
    deadline=d;
}

TimeHomework::TimeHomework(const DateTime& d,const std::string& t,const std::string& i,const std::string& a): Homework(t,i,a), deadline(d){}

DateTime TimeHomework::getDeadline() const{
return deadline;
}

int TimeHomework::getResult() const{
//da implementare
}

TimeHomework *TimeHomework::clone() const{
    return new TimeHomework(*this);
}
