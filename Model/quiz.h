#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include "myvector.h"
#include <map>


class Quiz{
private:
    std::string question;
    int point;
public:
    Quiz(const std::string& q,int p=0);

    std::string getQuestion() const;
    int getPoint() const;

    void setQuestion(const std::string& q);
    void setPoint(int p);

    virtual void showSolution() const=0;

    virtual Quiz *clone() const=0;
    virtual ~Quiz();
};




#endif // QUIZ_H
