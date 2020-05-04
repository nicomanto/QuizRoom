#ifndef HOMEWORKFORM_H
#define HOMEWORKFORM_H
#include <QPushButton>
#include <QLabel>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "baseform.h"
#include "loginform.h"

class HomeworkForm : public BaseForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> homework;
    QLabel* course_title;
    QScrollArea* scroll;

public:
    explicit HomeworkForm(QWidget *parent = nullptr);
    ~HomeworkForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();


signals:

public slots:
};

#endif // HOMEWORKFORM_H
