#ifndef MALUSQUIZ_H
#define MALUSQUIZ_H
#include "quiz.h"

class MalusQuiz : public Quiz{
protected:
    double total_malus;
    double malus_point; //il numero di malus che identifica una domanda

    virtual void resetPoint()=0;
    virtual void setPointCAnswer()=0;
public:
    MalusQuiz();
    MalusQuiz(const std::string& q,double mp, double tm=0);

    double getTotalMalus() const;
    double getMalusPoint() const;

    void setMalusPoint(double mp);
    void setTotalMalus(double m);
    void addTotalMalus(double m);

    virtual bool HaveMalus() const;
    virtual double CalcMalus() const=0;
    virtual double CalcPointQuiz()=0;


    virtual void showSolution()const=0;



    virtual const std::string SolutionToString()const=0;

    virtual Quiz *clone() const=0;

};

#endif // MALUSQUIZ_H
