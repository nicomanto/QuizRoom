#ifndef CLASSICQUIZFORM_H
#define CLASSICQUIZFORM_H


#include <QFile>
#include <QCheckBox>

#include "Model/myvector.h"
#include "quizbaseform.h"

class ClassicQuizForm: public QuizBaseForm{
     Q_OBJECT
private:


    MyVector<QCheckBox*> answers;  //possibili risposte


public:
    explicit ClassicQuizForm(QWidget *parent = nullptr);
    ~ClassicQuizForm()= default;

    virtual void addForm();


signals:

public slots:
};

#endif // CLASSICQUIZFORM_H
