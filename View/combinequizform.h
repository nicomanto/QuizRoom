#ifndef COMBINEQUIZFORM_H
#define COMBINEQUIZFORM_H

#include <QFile>
#include <QComboBox>

#include "Model/myvector.h"
#include "quizbaseform.h"

#include "Model/combinequiz.h"

class CombineQuizForm : public QuizBaseForm{
    Q_OBJECT
private:

   CombineQuiz* this_quiz;

   MyVector<QLabel*> elements;  //elementi da combinare
   MyVector<QComboBox*> answers; //possibili risposte (menu a tendina)

   virtual void addForm();

   virtual void randomize_answer();

public:
   explicit CombineQuizForm(CombineQuiz* q, QWidget *parent = nullptr);
   ~CombineQuizForm()= default;




signals:

public slots:
};

#endif // COMBINEQUIZFORM_H
