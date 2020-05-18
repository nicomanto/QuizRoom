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

    User* user;
    bool & relogin;

    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void setStyle();
public:
    explicit PrincipalForm(User* u,bool &r,QWidget *parent = nullptr);
    virtual ~PrincipalForm();


protected: signals:
    void to_new_page(PrincipalForm*);

protected slots:
    void to_login();
    void to_addform();

    virtual void to_next_page()=0;
    virtual void to_previous_page()=0;
};

#endif // PRINCIPALFORM_H
