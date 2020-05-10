#ifndef COURSEFORM_H
#define COURSEFORM_H
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QScrollArea>
#include <QString>

#include "menubutton.h"
#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"

class CourseForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> homework;
    MyVector <QPushButton *> homework_menu;

    QGroupBox* container_course;
    QGroupBox* container_homework;

    QVBoxLayout* info_course_layout;
    QHBoxLayout* center_layout;
    QGridLayout* scroll_layout;

    QLabel* course_title;
    QLabel* course_description;
    QLabel* course_code;
public:
    explicit CourseForm(const QString& title, QWidget *parent = nullptr);
    ~CourseForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);


signals:

public slots:
};

#endif // COURSEFORM_H
