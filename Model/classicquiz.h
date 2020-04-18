#ifndef CLASSICQUIZ_H
#define CLASSICQUIZ_H
#include "myvector.h"
#include "string"
#include "quiz.h"
class ClassicQuiz: public Quiz{
private:
    MyVector<std::string> correct_answer;
    MyVector<std::string> answer;
public:
    ClassicQuiz(const std::string& q, int p=0, int m=0);

    void addAnswer(const std::string& a);
    void addCorrectAnswer(const std::string& ca);

    bool isAnswer(const std::string& a) const;
    bool isCorrectAnswer(const std::string& ca);


    void addPoint(const std::string &ca);

    virtual void setMyPoint();
    virtual void setMalus(int m);
    virtual int CalcPointQuiz()const;
    virtual void setPointCAnswer();
    virtual void showSolution()const;

    virtual ClassicQuiz *clone() const;
};

#endif // CLASSICQUIZ_H
