#ifndef QUIZBASEFORM_H
#define QUIZBASEFORM_H


#include <QLabel>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"

#include "Model/quiz.h"


class QuizBaseForm : public BaseForm{
    Q_OBJECT

protected:


    QLabel* question;

    QGroupBox* container_answers;
    QGridLayout* answers_layout;

    virtual void addForm()=0;

    virtual void setStyle();


    virtual void randomize_answer()=0;
public:
    explicit QuizBaseForm(const QString& q, QWidget *parent = nullptr);
    virtual ~QuizBaseForm();


};

#endif // QUIZBASEFORM_H
