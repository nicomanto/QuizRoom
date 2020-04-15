#ifndef SCOREHOMEWORK_H
#define SCOREHOMEWORK_H
#include "homework.h"

class ScoreHomework : public Homework{
private:
    int score;


    static int calc_score();  // da implementare
    int setScore();
public:
    ScoreHomework(string t, string i=string(),string a=string());

    int getScore() const;
};

#endif // SCOREHOMEWORK_H
