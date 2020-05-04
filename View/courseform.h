#ifndef COURSEFORM_H
#define COURSEFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "baseform.h"
#include "loginform.h"

class CourseForm : public BaseForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course;
    QScrollArea* scroll;
public:
    explicit CourseForm(QWidget *parent = nullptr);
    ~CourseForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();


signals:

public slots:
};

#endif // COURSEFORM_H
