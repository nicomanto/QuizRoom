#ifndef TIMESCOREHOMEWORK_H
#define TIMESCOREHOMEWORK_H
#include "scorehomework.h"
#include "timehomework.h"

class TimeScoreHomework : public TimeHomework, public ScoreHomework{
private:
    static int day_max_malus;
public:
    TimeScoreHomework();
    TimeScoreHomework(const DateTime& d, const string& t,const string& i=string(),const string& a=string());


    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;
    virtual double getResult() const;  //ritorna un punteggio in base ai voti dei quiz + (-1 se consegnato dopo la scadenza, -2 se dopo un giorno, -3 se dopo due giorni)
    virtual TimeScoreHomework *clone() const;
};



#endif // TIMESCOREHOMEWORK_H
