#ifndef CONTAINERQUIZFORM_H
#define CONTAINERQUIZFORM_H

#include "principalform.h"
#include "quizbaseform.h"
#include "Model/myvector.h"
#include "classicquizform.h"
#include "combinequizform.h"


class ContainerQuizForm : public PrincipalForm{
    Q_OBJECT
private:

    MyVector<QuizBaseForm*> quiz; //vettore della vista dei quiz
    MyVector<QGroupBox*> quiz_box; //vettore della domanda (contenitore del quiz)

    QVBoxLayout* scroll_layout;  //layout della scroll area

    QPushButton* end_quiz; //bottone per terminare il quiz ed inviare le risposte
public:
    explicit ContainerQuizForm(QWidget *parent = nullptr);
    ~ContainerQuizForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();
signals:

public slots:
};

#endif // CONTAINERQUIZFORM_H
