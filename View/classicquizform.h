#ifndef CLASSICQUIZFORM_H
#define CLASSICQUIZFORM_H



#include <QPushButton>

#include "quizbaseform.h"

#include "Model/myvector.h"
#include "Model/classicquiz.h"


class ClassicQuizForm: public QuizBaseForm{
     Q_OBJECT
private:

    ClassicQuiz* this_quiz;

    MyVector<QPushButton*> answers;  //possibili risposte

    virtual void addForm();

    virtual void setStyle();

    virtual void randomize_answer();


public:
    explicit ClassicQuizForm(Controller& c, ClassicQuiz* q,QWidget *parent = nullptr);
    ~ClassicQuizForm()= default;



private slots:
    //invia le risposte al quiz date dall'utente al controller
    virtual void getAnswers();
};

#endif // CLASSICQUIZFORM_H
