#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QDialog>
#include <QMenuBar>
#include "loginform.h"
#include "modifyaddform.h"
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>
#include "Model/controller.h"

#include <QDialogButtonBox>


class PrincipalForm : public BaseForm{
    Q_OBJECT
protected:

    User* user;
    Controller& control;
    bool & relogin;

    QMenuBar* menubar;
    QScrollArea* scroll;

    QGroupBox* container_scroll;  //contenitore della scroll area

    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void setStyle();


public:
    explicit PrincipalForm(User* u,Controller& c,bool &r,QWidget *parent = nullptr);
    virtual ~PrincipalForm();

    virtual PrincipalForm *clone() const=0;


protected: signals:
    void to_new_page(PrincipalForm*);
    void previous_page();
    void update_previous_page();

protected slots:
    void to_login();
    void to_addform(const QString& title="", const QString& description="");


    virtual void confirm_addform(const QString&, const QString&)=0;

    virtual void to_next_page(int i)=0;
    virtual void to_previous_page();
    virtual void to_update_previous_page();
};

#endif // PRINCIPALFORM_H
