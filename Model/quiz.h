#ifndef QUIZ_H
#define QUIZ_H
#include <string>

class Quiz{
protected:
    std::string question;
    double point_correct_answer;
    double my_point;

    static double total_point;

    void addMyPoint(double p); //aggiunge p a my_point
    virtual void setPointCAnswer()=0; //setta il punteggio che si può ottenre
                                       //da una domanda in base a quando domande ci sono e al total_point


public:
    Quiz();
    Quiz(const std::string& q);

    const std::string& getQuestion() const;
    double getTotalPoint() const;
    double getPointAnswer() const;
    virtual double getMyPoint() const;

    void setQuestion(const std::string& q);

    virtual bool HaveMalus() const=0;
    virtual double CalcPointQuiz()const =0; //calcola il punteggio ottenuto nel quiz


    virtual void showSolution()const=0;

    virtual const std::string SolutionToString()const=0;

    virtual void clear_all_answers()=0; //elimina tutte le rispote e domande inserite

    virtual void resetPoint()=0;

    virtual Quiz *clone() const=0;
    virtual ~Quiz();
};




#endif // QUIZ_H
