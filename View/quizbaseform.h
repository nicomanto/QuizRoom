#ifndef QUIZBASEFORM_H
#define QUIZBASEFORM_H


#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFile>

#include "baseform.h"

#include "Model/quiz.h"
#include "Control/controller.h"


class QuizBaseForm : public BaseForm{
    Q_OBJECT

protected:

    Controller& control;
    QLabel* question;

    QGroupBox* container_answers;
    QGridLayout* answers_layout;

    virtual void addForm()=0;

    virtual void setStyle();

    //inserisce le risposte in ordine sparso ad ogni creazione di un quiz
    virtual void randomize_answer()=0;
public:
    explicit QuizBaseForm(Controller& c,const QString& q, QWidget *parent = nullptr);
    virtual ~QuizBaseForm();


private slots:

    //invia le risposte al quiz date dall'utente al controller
    virtual void getAnswers() =0;


};

#endif // QUIZBASEFORM_H
