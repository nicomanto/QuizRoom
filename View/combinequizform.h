#ifndef COMBINEQUIZFORM_H
#define COMBINEQUIZFORM_H

#include <QFile>
#include <QComboBox>

#include "Model/myvector.h"
#include "quizbaseform.h"


class CombineQuizForm : public QuizBaseForm{
    Q_OBJECT
private:

   MyVector<QLabel*> elements;  //elementi da combinare
   MyVector<QComboBox*> answers; //possibili risposte (menu a tendina)

   virtual void addForm();

public:
   explicit CombineQuizForm(QWidget *parent = nullptr);
   ~CombineQuizForm()= default;




signals:

public slots:
};

#endif // COMBINEQUIZFORM_H
