#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QMenuBar>
#include <QScrollArea>
#include <QPushButton>

#include "baseform.h"

class PrincipalForm : public BaseForm{
    Q_OBJECT
protected:
    QMenuBar* menubar;
    QScrollArea* scroll;
public:
    explicit PrincipalForm(QWidget *parent = nullptr);
    virtual ~PrincipalForm();

    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void addMenuButton(QPushButton* b)=0;

};

#endif // PRINCIPALFORM_H
