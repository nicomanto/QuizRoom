#ifndef HOMEWORKFORM_H
#define HOMEWORKFORM_H
#include <QLabel>
#include <QGroupBox>
#include <QSignalMapper>

#include "principalform.h"
#include "containerquizform.h"
#include "containeraddquizform.h"

#include "Model/homework.h"

class HomeworkForm : public PrincipalForm{
    Q_OBJECT
private:

    Homework* this_homework;

    QLabel* homework_title;
    QLabel* homework_instructions;

    QWidget* container_info_quiz;  //informazioni del quiz (score,deadline)
    QVBoxLayout* layout_container_info_quiz;  //layout di container_info_quiz

    QLabel* score;
    QLabel* deadline;

    QPushButton* start_quiz;
    QPushButton* add_quiz;

    QWidget* container_button; //contenitore dei
    QHBoxLayout* layout_button; //layout del widget dei bottoni




    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();
public:
    explicit HomeworkForm(User* u,Controller& c,Homework* h,bool & r,QWidget *parent = nullptr);
    ~HomeworkForm()= default;

    virtual HomeworkForm *clone() const;

signals:

private slots:
    //creazione form per la pagina dell'aggiunta dei quiz
    void to_addquiz();
    //invio delle informazioni del compito in cui mi trovo per la modifica dei dati
    void to_homework_info();

    virtual void confirm_addform(const QString&, const QString&);
    virtual void to_next_page(int index);

    //eliminazione del compito in cui mi trovo
    void del_homework();
};

#endif // HOMEWORKFORM_H
