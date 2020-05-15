#ifndef ADDCOMBINEQUIZFORM_H
#define ADDCOMBINEQUIZFORM_H


#include "addquizform.h"
#include "Model/myvector.h"


class AddCombineQuizForm : public AddQuizForm{
    Q_OBJECT
private:

    MyVector<QLineEdit*> options_form;  //opzione da combinare
    MyVector<QLineEdit*> answers_form;  //risposta



    //in questo caso vanno inserite le combinazioni giuste, poi sarà compito del programma disordinarle per lo studente


    virtual void addForm();

    virtual void setStyle();
public:
    explicit AddCombineQuizForm(int number_question, QWidget *parent = nullptr);
    ~AddCombineQuizForm()=default;


signals:

public slots:
};

#endif // ADDCOMBINEQUIZFORM_H
