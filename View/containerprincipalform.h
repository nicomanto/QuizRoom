#ifndef CONTAINERPRINCIPALFORM_H
#define CONTAINERPRINCIPALFORM_H

#include "mainform.h"

class ContainerPrincipalForm : public BaseForm{
    Q_OBJECT

private:
    PrincipalForm* main_window;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerPrincipalForm(QWidget *parent = nullptr);
    ~ContainerPrincipalForm()= default;





signals:

private slots:
    void update_main_window(PrincipalForm* p);
};

#endif // CONTAINERPRINCIPALFORM_H
