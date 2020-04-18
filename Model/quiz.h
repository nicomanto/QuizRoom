#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include "myvector.h"
#include <map>


class Quiz{
protected:
    std::string question;
    int total_point;
    int point_correct_answer;
    int malus;
    int my_point;
public:
    Quiz(const std::string& q,int t=0, int pc=0, int m=0);

    std::string getQuestion() const;
    int getTotalPoint() const;
    int getPointAnswer() const;
    int getMalus() const;
    int getMyPoint() const;

    void setQuestion(const std::string& q);
    void setTotalPoint(int p);


    virtual void setMyPoint()=0;
    virtual void setMalus(int m)=0;
    virtual int CalcPointQuiz()const=0;

    virtual void setPointCAnswer()=0;
    virtual void showSolution()const=0;

    virtual Quiz *clone() const=0;
    virtual ~Quiz();
};




#endif // QUIZ_H
