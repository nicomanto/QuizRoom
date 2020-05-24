#ifndef CLASSICQUIZFORM_H
#define CLASSICQUIZFORM_H


#include <QFile>
#include <QPushButton>

#include "Model/myvector.h"
#include "Model/classicquiz.h"
#include "quizbaseform.h"

class ClassicQuizForm: public QuizBaseForm{
     Q_OBJECT
private:

    ClassicQuiz* this_quiz;

    MyVector<QPushButton*> answers;  //possibili risposte

    virtual void addForm();

    virtual void setStyle();

    virtual void randomize_answer();


public:
    explicit ClassicQuizForm(ClassicQuiz* q,QWidget *parent = nullptr);
    ~ClassicQuizForm()= default;




signals:

public slots:

    virtual void getAnswers();
};

#endif // CLASSICQUIZFORM_H
