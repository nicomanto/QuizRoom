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

class HomeworkForm : public PrincipalForm{
    Q_OBJECT
private:

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
    explicit HomeworkForm(QWidget *parent = nullptr);
    ~HomeworkForm()= default;


signals:

private slots:
    void to_addquiz();

    virtual void to_next_page();
    virtual void to_previous_page();
};

#endif // HOMEWORKFORM_H
