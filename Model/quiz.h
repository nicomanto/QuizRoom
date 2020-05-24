#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include "myvector.h"
#include <map>


class Quiz{
protected:
    std::string question;
    double total_point;
    double point_correct_answer;
    double my_point;
public:
    Quiz();
    Quiz(const std::string& q);

    std::string getQuestion() const;
    double getTotalPoint() const;
    double getPointAnswer() const;
    double getMyPoint() const;

    void setQuestion(const std::string& q);
    void setTotalPoint(int p);
    void addMyPoint(double p);
    void addPointCorrectAnswer(double m);

    virtual bool HaveMalus() const=0;
    virtual double CalcPointQuiz()=0;

    virtual void setPointCAnswer()=0;
    virtual void showSolution()const=0;

    virtual std::string SolutionToString()const=0;

    virtual void clear_all_answers()=0;

    virtual Quiz *clone() const=0;
    virtual ~Quiz();
};




#endif // QUIZ_H
