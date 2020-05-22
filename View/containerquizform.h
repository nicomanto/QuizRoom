#ifndef CONTAINERQUIZFORM_H
#define CONTAINERQUIZFORM_H

#include "principalform.h"
#include "homeworkform.h"
#include "quizbaseform.h"
#include "Model/myvector.h"
#include "classicquizform.h"
#include "combinequizform.h"


class ContainerQuizForm : public PrincipalForm{
    Q_OBJECT
private:

    const MyVector<Quiz*>& quiz_model;

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
    explicit ContainerQuizForm(User* u,Controller& c,const MyVector<Quiz*>& q,bool & r,QWidget *parent = nullptr);
    ~ContainerQuizForm()= default;

    virtual ContainerQuizForm *clone() const;
signals:

private slots:

    virtual void confirm_addform(const QString&, const QString&){}
    virtual void to_next_page(int index);
    //virtual void to_previous_page();
};

#endif // CONTAINERQUIZFORM_H
