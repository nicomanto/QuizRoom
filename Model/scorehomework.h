#ifndef SCOREHOMEWORK_H
#define SCOREHOMEWORK_H
#include "homework.h"

class ScoreHomework : virtual public Homework{
private:
    int total_score;


      // da implementare
    void setScore(int ts);
    //int calc_score() const;
public:
    ScoreHomework(int ts,const string& t,const string& i=string(),const string& a=string());

    int getScore() const;

    virtual int getResult() const;
    virtual ScoreHomework *clone() const;
    //virtual ~ScoreHomework() {}
};

#endif // SCOREHOMEWORK_H
