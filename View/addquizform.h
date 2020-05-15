#ifndef ADDQUIZFORM_H
#define ADDQUIZFORM_H


#include <QLineEdit>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"


class AddQuizForm : public BaseForm{
    Q_OBJECT

protected:
    QGroupBox* box_question;
    QGroupBox* box_answer;

    QVBoxLayout* layout_box_question;
    QGridLayout* layout_box_answer;

    QLineEdit *question_form;


    virtual void addForm()=0;

    virtual void setStyle();

public:
    explicit AddQuizForm(int number_question, QWidget *parent = nullptr);
    virtual ~AddQuizForm();



signals:

public slots:

};

#endif // ADDQUIZFORM_H
