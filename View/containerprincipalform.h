#ifndef CONTAINERPRINCIPALFORM_H
#define CONTAINERPRINCIPALFORM_H

#include "mainform.h"

#include "Model/teacher.h"
#include "Model/student.h"

class ContainerPrincipalForm : public BaseForm{
    Q_OBJECT

private:
    User* user;
    bool& relogin;
    Controller& control;

    PrincipalForm* main_window;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerPrincipalForm(User* u,Controller& c,bool &r,QWidget *parent = nullptr);
    ~ContainerPrincipalForm()= default;





signals:

private slots:
    void update_main_window(PrincipalForm* p);
    void previous_main_window();
    void update_previous_main_window();
};

#endif // CONTAINERPRINCIPALFORM_H
