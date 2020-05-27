#ifndef COMBINEQUIZFORM_H
#define COMBINEQUIZFORM_H


#include <QComboBox>

#include "quizbaseform.h"

#include "Model/myvector.h"
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




private slots:
   //invia le risposte al quiz date dall'utente al controller
   virtual void getAnswers();
};

#endif // COMBINEQUIZFORM_H
