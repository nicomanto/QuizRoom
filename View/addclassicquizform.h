#ifndef ADDCLASSICQUIZFORM_H
#define ADDCLASSICQUIZFORM_H

#include<QCheckBox>

#include "addquizform.h"
#include "errordialog.h"
#include "Model/myvector.h"



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


private slots:

    //invia i dati del quiz al controller
    virtual void setInformation();
};

#endif // ADDCLASSICQUIZFORM_H
