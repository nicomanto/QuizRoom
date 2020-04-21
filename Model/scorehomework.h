#ifndef SCOREHOMEWORK_H
#define SCOREHOMEWORK_H
#include "homework.h"

class ScoreHomework : virtual public Homework{
private:
    double total_score;

    void addTotalScore(double p);
    void removeTotalScore(double p);
public:
    ScoreHomework();
    ScoreHomework(const string& t,const string& i=string(),const string& a=string());

    double getTotalScore() const;
    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;

    virtual void addQuizContainer(const QuizContainer& q);
    virtual void removeQuizContainer(const QuizContainer& q);

    virtual double getResult() const;   //ritorna la media del punteggio dei quiz
    virtual ScoreHomework *clone() const;
    //virtual ~ScoreHomework() {}
};

#endif // SCOREHOMEWORK_H
