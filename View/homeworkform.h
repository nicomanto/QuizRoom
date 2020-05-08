#ifndef HOMEWORKFORM_H
#define HOMEWORKFORM_H
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QScrollArea>
#include <QString>

#include "menubutton.h"
#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"

class HomeworkForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> homework;
    MyVector <QPushButton *> homework_menu;

    QVBoxLayout* info_course;
    QHBoxLayout* center;
    QGridLayout* container_grid;

    QLabel* course_title;
    QLabel* course_description;
    QLabel* course_code;
public:
    explicit HomeworkForm(const QString& title, QWidget *parent = nullptr);
    ~HomeworkForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);

signals:

public slots:
};

#endif // HOMEWORKFORM_H
