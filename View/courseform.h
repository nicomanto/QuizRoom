#ifndef COURSEFORM_H
#define COURSEFORM_H
#include "Model/myvector.h"
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QFile>
#include "formvirtual.h"
#include "loginform.h"

class CourseForm : public FormVirtual{
    Q_OBJECT
private:
    MyVector <QPushButton *> course;

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
