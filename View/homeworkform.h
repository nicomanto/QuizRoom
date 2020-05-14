#ifndef HOMEWORKFORM_H
#define HOMEWORKFORM_H
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QGroupBox>

#include "principalform.h"

class HomeworkForm : public PrincipalForm{
    Q_OBJECT
private:

    QLabel* homework_title;
    QLabel* homework_instructions;

    QGroupBox* container_info_quiz;  //informazioni del quiz (score,deadline)
    QVBoxLayout* layout_container_info_quiz;  //layout di container_info_quiz

    QLabel* score;
    QLabel* deadline;

    QPushButton* start_quiz;


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();
public:
    explicit HomeworkForm(QWidget *parent = nullptr);
    ~HomeworkForm()= default;


signals:

public slots:
};

#endif // HOMEWORKFORM_H
