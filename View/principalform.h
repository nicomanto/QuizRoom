#ifndef PRINCIPALFORM_H
#define PRINCIPALFORM_H

#include <QDialog>
#include <QMenuBar>
#include <QScrollArea>
#include <QGroupBox>
//#include <QPushButton>

#include "loginform.h"
#include "modifyaddform.h"

#include "Control/controller.h"


class PrincipalForm : public BaseForm{
    Q_OBJECT
protected:

    User* user; //utente con cui si è fatto l'accesso
    Controller& control; //controller
    bool & relogin;  //variabile booleana nel caso serva fare il relogin

    QMenuBar* menubar;
    QScrollArea* scroll;

    QGroupBox* container_scroll;  //contenitore della scroll area

    //aggiunta della barra del menu nella parte superiore della pagina
    virtual void addMenu()=0;

    virtual void addForm()=0;

    virtual void setStyle();


public:
    explicit PrincipalForm(User* u,Controller& c,bool &r,QWidget *parent = nullptr);
    virtual ~PrincipalForm();


    //metodo clone che verrà implementato senza costruttore di copia perchè Qt non permette la costruzione di copia dei Q_OBJECT
    virtual PrincipalForm *clone() const=0;


signals:
    //dico qual è la pagina successiva da raggiungere
    void to_new_page(PrincipalForm*);

    //ritono alla pagina precedene
    void previous_page();
    //aggiorno la pagina precedente
    void update_previous_page();

protected slots:
    //ritorno al login
    void to_login();

    //aggiunge la form per l'aggiunta o modifica di una principal form
    void to_addform(const QString& title="", const QString& description="");

    //invio dei dati aggiunti/modificati al controllore
    virtual void confirm_addform(const QString&, const QString&)=0;

    //riferimento alla pagina successiva in base all posizione dell'array mostrato (array course o array homework)
    virtual void to_next_page(int i)=0;

    //slot per emettere previous_page()
    virtual void to_previous_page();

    //slot per emettere update_previous_page()
    virtual void to_update_previous_page();
};

#endif // PRINCIPALFORM_H
