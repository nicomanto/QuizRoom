#ifndef ADDQUIZFORM_H
#define ADDQUIZFORM_H


#include <QLineEdit>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"

#include "Model/myvector.h"
#include "Model/homework.h"
#include "Control/controller.h"


class AddQuizForm : public BaseForm{
    Q_OBJECT

protected:
    Controller& control;
    Homework* this_homework;

    QGroupBox* box_question;
    QGroupBox* box_answer;

    QVBoxLayout* layout_box_question;
    QGridLayout* layout_box_answer;

    QLineEdit *question_form;


    virtual void addForm()=0;

    virtual void setStyle();

public:
    explicit AddQuizForm(Controller&  c, Homework* h,int number_question, QWidget *parent = nullptr);
    virtual ~AddQuizForm();


private slots:

    //invia i dati del quiz al controller
    virtual void setInformation()=0;

};

#endif // ADDQUIZFORM_H
