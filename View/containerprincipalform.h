#ifndef CONTAINERPRINCIPALFORM_H
#define CONTAINERPRINCIPALFORM_H

#include "mainform.h"

#include "Model/user.h"

class ContainerPrincipalForm : public BaseForm{
    Q_OBJECT

private:
    Controller& control;

    PrincipalForm* main_window;

    virtual void addForm();

    virtual void setStyle();


public:
    explicit ContainerPrincipalForm(User* u,Controller& c,bool &r,QWidget *parent = nullptr);
    ~ContainerPrincipalForm()= default;

private slots:
    //aggiornamento della pagina che è contenuta nel container dellle principal form
    void update_main_window(PrincipalForm* p);
    //ritorno alla pagina precedente di quella attuale, cioè quella in cima allo stack
    void previous_main_window();
    //aggiornamento alla pagina precedente dopo aver effettuato opportune modifiche
    void update_previous_main_window();
};

#endif // CONTAINERPRINCIPALFORM_H
