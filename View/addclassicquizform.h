#ifndef ADDCLASSICQUIZFORM_H
#define ADDCLASSICQUIZFORM_H

#include<QCheckBox>
#include<QFile>

#include "addquizform.h"
#include "Model/myvector.h"
#include "errordialog.h"


class AddClassicQuizForm : public AddQuizForm{
    Q_OBJECT
private:

    MyVector<QCheckBox*> check_answers; //spunta per definire se la risposta è una riposta corretta
    MyVector<QLineEdit*> answers_form; //risposta

    virtual void addForm();

    virtual void setStyle();

public:
    explicit AddClassicQuizForm(Controller& c, Homework* h, int number_question,QWidget *parent = nullptr);
    ~AddClassicQuizForm()=default;


public slots:
    virtual void setInformation();
};

#endif // ADDCLASSICQUIZFORM_H
