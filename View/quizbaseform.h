#ifndef QUIZBASEFORM_H
#define QUIZBASEFORM_H


#include <QLabel>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"


class QuizBaseForm : public BaseForm{
    Q_OBJECT

protected:
    QLabel* question;

    QGroupBox* container_answers;
    QGridLayout* answers_layout;
public:
    explicit QuizBaseForm(QWidget *parent = nullptr);
    virtual ~QuizBaseForm();

    virtual void addForm()=0;

    virtual void setStyle();
};

#endif // QUIZBASEFORM_H
