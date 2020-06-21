#ifndef SCOREHOMEWORK_H
#define SCOREHOMEWORK_H
#include "homework.h"

class ScoreHomework : virtual public Homework{
public:
    ScoreHomework();
    ScoreHomework(const string& t,const string& i=string());

    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;
    virtual bool haveResult() const;

    virtual double getResult() const;   //ritorna la media del punteggio dei quiz
    virtual ScoreHomework *clone() const;
};

#endif // SCOREHOMEWORK_H
