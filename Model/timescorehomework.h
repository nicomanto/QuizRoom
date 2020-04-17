#ifndef TIMESCOREHOMEWORK_H
#define TIMESCOREHOMEWORK_H
#include "scorehomework.h"
#include "timehomework.h"

class TimeScoreHomework : public TimeHomework, ScoreHomework{
public:
    TimeScoreHomework(const DateTime& d, int ts, const string& t,const string& i=string(),const string& a=string());

    virtual int getResult() const;
    virtual TimeScoreHomework *clone() const;
};

#endif // TIMESCOREHOMEWORK_H
