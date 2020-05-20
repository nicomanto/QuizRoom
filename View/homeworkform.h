#ifndef HOMEWORKFORM_H
#define HOMEWORKFORM_H
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QGroupBox>

#include "principalform.h"
#include "mainform.h"
#include "containerquizform.h"
#include "containeraddquizform.h"
#include "courseform.h"

#include "Model/timescorehomework.h"
#include "Model/course.h"



class HomeworkForm : public PrincipalForm{
    Q_OBJECT
private:

    Homework* this_homework;
    Course* course_father;

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
    explicit HomeworkForm(User* u,Controller& c,Homework* h,Course* course,bool & r,QWidget *parent = nullptr);
    ~HomeworkForm()= default;


signals:

private slots:
    void to_addquiz();

    virtual void confirm_addform(const QString&, const QString&){}
    virtual void to_next_page(int index);
    virtual void to_previous_page();

    void del_homework();
};

#endif // HOMEWORKFORM_H
