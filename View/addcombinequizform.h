#ifndef ADDCOMBINEQUIZFORM_H
#define ADDCOMBINEQUIZFORM_H


#include "addquizform.h"
#include "Model/myvector.h"
#include "errordialog.h"




class AddCombineQuizForm : public AddQuizForm{
    Q_OBJECT
private:


    MyVector<QLineEdit*> options_form;  //opzione da combinare
    MyVector<QLineEdit*> answers_form;  //risposta



    //in questo caso vanno inserite le combinazioni giuste, poi sarà compito del programma disordinarle per lo studente


    virtual void addForm();

    virtual void setStyle();
public:
    explicit AddCombineQuizForm(Controller& c,Homework* h,int number_question, QWidget *parent = nullptr);
    ~AddCombineQuizForm()=default;


signals:
    //void send_information(const std::string& question, const MyVector<std::string>& elements_to_combine,const MyVector<std::string>& answers );

private slots:

    //invia i dati del quiz al controller
    virtual void setInformation();
};

#endif // ADDCOMBINEQUIZFORM_H
