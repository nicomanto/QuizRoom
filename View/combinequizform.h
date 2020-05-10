#ifndef COMBINEQUIZFORM_H
#define COMBINEQUIZFORM_H

#include <QFile>
#include <QComboBox>

#include "Model/myvector.h"
#include "quizbaseform.h"


class CombineQuizForm : public QuizBaseForm{
    Q_OBJECT
private:

   MyVector<QLabel*> elements;
   MyVector<QComboBox*> answers;

public:
   explicit CombineQuizForm(QWidget *parent = nullptr);
   ~CombineQuizForm()= default;

   virtual void addForm();


signals:

public slots:
};

#endif // COMBINEQUIZFORM_H
