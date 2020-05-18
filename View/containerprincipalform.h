#ifndef CONTAINERPRINCIPALFORM_H
#define CONTAINERPRINCIPALFORM_H

#include "mainform.h"

#include "Model/teacher.h"
#include "Model/student.h"

class ContainerPrincipalForm : public BaseForm{
    Q_OBJECT

private:


    PrincipalForm* main_window;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerPrincipalForm(User* u, QWidget *parent = nullptr);
    ~ContainerPrincipalForm()= default;





signals:

private slots:
    void update_main_window(PrincipalForm* p);
};

#endif // CONTAINERPRINCIPALFORM_H
