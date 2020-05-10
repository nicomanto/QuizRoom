#ifndef MAINFORM_H
#define MAINFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"
#include "menubutton.h"

class MainForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course;
    MyVector <QPushButton *> course_menu;

    QGroupBox* container_scroll;
    QGridLayout* scroll_layout;
public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm()= default;

    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);

signals:

public slots:
};

#endif // MAINFORM_H
