#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QDialog>
#include <QMenuBar>
#include "loginform.h"
#include "modifyaddform.h"
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>

#include <QDialogButtonBox>


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


protected slots:
    void to_login();
    void to_addform();
    virtual void previous_page()=0;
};

#endif // PRINCIPALFORM_H
