#ifndef CONTAINERADDQUIZFORM_H
#define CONTAINERADDQUIZFORM_H


#include "principalform.h"
#include "Model/myvector.h"
#include "addcombinequizform.h"
#include "addclassicquizform.h"
#include "homeworkform.h"
class ContainerAddQuizForm : public PrincipalForm{
    Q_OBJECT
private:

    MyVector<AddQuizForm*> quiz; //vettore della vista dei quiz da aggiungere
    QWidget* container_quiz;
    QVBoxLayout* layout_container_quiz;

    QVBoxLayout* scroll_layout;  //layout della scroll area

    QPushButton* end; //bottone per terminare il l'aggiunta dei quiz
    QPushButton* add_combine;  //aggiunge il form addcombinequizform
    QPushButton* add_classic; //aggiunge il form addclassicquizform

    QWidget* container_button; //contenitore dei
    QHBoxLayout* layout_button; //layout del widget dei bottoni


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerAddQuizForm(User* u,QWidget *parent = nullptr);
    ~ContainerAddQuizForm()= default;



signals:

public slots:
private slots:
    void addCombineWidget();
    void addClassicWidget();

    virtual void to_next_page();
    virtual void to_previous_page();
};

#endif // CONTAINERADDQUIZFORM_H
