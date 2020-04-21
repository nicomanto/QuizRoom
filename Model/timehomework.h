#ifndef TIMEHOMEWORK_H
#define TIMEHOMEWORK_H

#include "homework.h"
#include "datetime.h"
class TimeHomework : virtual public Homework{
protected:
    DateTime deadline;

    void setDeadline (const DateTime& d);
public:
    TimeHomework();
    TimeHomework(const DateTime& d,const string& t,const string& i=string(),const string& a=string());

    DateTime getDeadline() const;

    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;
    virtual double getResult() const;  //ritorna 1 se la consegna è stata fatta prima o == alla deadline, 0 altrimenti
    virtual TimeHomework *clone() const;

};

#endif // TIMEHOMEWORK_H
