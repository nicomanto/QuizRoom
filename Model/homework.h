#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>
#include "quizcontainer.h"
using std::string;

class Homework{
protected:
    string title;
    string instructions;
    MyVector<QuizContainer> container_q;      // modulo per quiz (struttura del contenitore dei quiz)

public:
    Homework();
    Homework(const string& t, const string& i=string());

    string getTitle() const;
    string getInstructions() const;
    const MyVector<QuizContainer>& getContainerQuiz() const; //ritorna il vettore che contiene i container dei quiz

    void setTitle(const string& t);
    void setInstructions(const string& i);
    bool isDone() const;

    virtual void addQuizContainer(const QuizContainer& q);
    virtual void removeQuizContainer(const QuizContainer& q);
    virtual bool isScoreHomework() const;
    virtual bool isTimeHomework() const;
    virtual double getResult() const; //ritorna il risultato del quiz
    virtual ~Homework();
};

#endif // HOMEWORK_H
