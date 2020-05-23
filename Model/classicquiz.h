#ifndef CLASSICQUIZ_H
#define CLASSICQUIZ_H
#include "myvector.h"
#include "string"
#include "malusquiz.h"
class ClassicQuiz: public MalusQuiz{
private:
    MyVector<std::string> correct_answer;
    MyVector<std::string> answer;

public:
    ClassicQuiz();
    ClassicQuiz(const std::string& q, double tp=100, double mp=0, double tm=0);

    const MyVector<std::string>& getCorrectAnswer() const;
    const MyVector<std::string>& getAnswers() const;


    void addAnswer(const std::string& a);
    void addCorrectAnswer(const std::string& ca);
    void removeAnswer(const std::string& a);
    void removeCorrectAnswer(const std::string& ca);
    bool isAnswer(const std::string& a) const;
    bool isCorrectAnswer(const std::string& ca);

    void addPoint(const std::string &ca); //aggiunge il punteggio in base se la risposta è esatta, oppure aggiunge un malus

    virtual double CalcMalus() const;
    virtual double CalcPointQuiz()const;
    virtual void setPointCAnswer();
    virtual void showSolution()const;

    virtual void clear_all_answers();

    virtual ClassicQuiz *clone() const;
};

#endif // CLASSICQUIZ_H
