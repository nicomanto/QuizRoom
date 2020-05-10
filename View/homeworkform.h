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

    QGroupBox* container_info_quiz;
    QVBoxLayout* layout_container_info_quiz;

    QLabel* score;
    QLabel* deadline;

    QPushButton* quiz;
public:
    explicit HomeworkForm(QWidget *parent = nullptr);
    ~HomeworkForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton *b);
signals:

public slots:
};

#endif // HOMEWORKFORM_H
