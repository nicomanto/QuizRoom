#ifndef CONTAINERQUIZFORM_H
#define CONTAINERQUIZFORM_H

#include "principalform.h"
#include "homeworkform.h"
#include "quizbaseform.h"
#include "classicquizform.h"
#include "combinequizform.h"


#include "Model/myvector.h"


class ContainerQuizForm : public PrincipalForm{
    Q_OBJECT
private:

    Homework* this_homework;

    MyVector<QuizBaseForm*> quiz; //vettore della vista dei quiz
    MyVector<QGroupBox*> quiz_box; //vettore della domanda (contenitore del quiz)

    QVBoxLayout* scroll_layout;  //layout della scroll area

    QPushButton* end_quiz; //bottone per terminare il quiz ed inviare le risposte


    QWidget* container_button; //contenitore del bottone
    QVBoxLayout* layout_button; //layout del widget del bottone


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerQuizForm(User* u,Controller& c,Homework* h,bool & r,QWidget *parent = nullptr);
    ~ContainerQuizForm()= default;

    virtual ContainerQuizForm *clone() const;
signals:
    //emette il segnale che dice di essere pronto per ricevere le risposte dai figli (i singoli quiz)
    void getAnswers();

private slots:

    virtual void confirm_addform(const QString&, const QString&){}
    virtual void to_next_page(int index);

    //mostra una form con le risposte corrette e i punteggi ottenuti per ciascuna domanda
    void show_result();
};

#endif // CONTAINERQUIZFORM_H
