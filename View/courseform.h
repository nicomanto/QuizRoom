#ifndef COURSEFORM_H
#define COURSEFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"
#include "menubutton.h"

class CourseForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course;
    MyVector <QPushButton *> course_menu;

    QGridLayout* container_grid;
public:
    explicit CourseForm(QWidget *parent = nullptr);
    ~CourseForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);

signals:

public slots:
};

#endif // COURSEFORM_H
