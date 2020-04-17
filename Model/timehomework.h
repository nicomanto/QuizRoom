#ifndef TIMEHOMEWORK_H
#define TIMEHOMEWORK_H

#include "homework.h"
#include "datetime.h"
class TimeHomework : virtual public Homework{
private:
    DateTime deadline;

    void setDeadline (const DateTime& d);
public:
    TimeHomework(const DateTime& d, string t, string i=string(),string a=string());

    DateTime getDeadline() const;

    virtual int getResult() const;
    virtual TimeHomework *clone() const;

};

#endif // TIMEHOMEWORK_H
