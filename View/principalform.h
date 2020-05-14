#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QMenuBar>
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>

#include "baseform.h"

class PrincipalForm : public BaseForm{
    Q_OBJECT
protected:
    QMenuBar* menubar;
    QScrollArea* scroll;

    QGroupBox* container_scroll;  //contenitore della scroll area

    virtual void addMenu()=0;

    virtual void addForm()=0;
public:
    explicit PrincipalForm(QWidget *parent = nullptr);
    virtual ~PrincipalForm();



};

#endif // PRINCIPALFORM_H
