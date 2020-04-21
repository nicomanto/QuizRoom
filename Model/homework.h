#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>
#include "quizcontainer.h"
using std::string;

class Homework{
protected:
    string title;
    string instructions;
    string arguments;
    MyVector<QuizContainer> container_q;      // modulo per quiz (struttura del contenitore dei quiz)

public:
    Homework();
    Homework(const string& t, const string& i=string(),const string& a=string());

    string getTitle() const;
    string getInstructions() const;
    string getArguments() const;
    const MyVector<QuizContainer>& getContainerQuiz() const; //ritorna il vettore che contiene i container dei quiz

    void setTitle(const string& t);
    void setInstructions(const string& i);
    void setArguments(const string& a);

    virtual void addQuizContainer(const QuizContainer& q);
    virtual void removeQuizContainer(const QuizContainer& q);
    virtual bool isScoreHomework() const=0;
    virtual bool isTimeHomework() const=0;
    virtual double getResult() const=0; //ritorna il risultato del quiz
    virtual Homework* clone() const=0;
    virtual ~Homework();
};

#endif // HOMEWORK_H
