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
    ScoreHomework(const string& t,const string& i=string());

    double getTotalScore() const;
    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;

    virtual void addQuizContainer(const QuizContainer& q); //ridefinizione perchè calcola il nuovo totale con l'aggiunta del container quiz
    virtual void removeQuizContainer(const QuizContainer& q); //ridefinizione perchè calcola il nuovo totale con la rimozione del container quiz

    virtual double getResult() const;   //ritorna la media del punteggio dei quiz
    virtual ScoreHomework *clone() const;
};

#endif // SCOREHOMEWORK_H
