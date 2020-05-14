#ifndef MAINFORM_H
#define MAINFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "principalform.h"
#include "loginform.h"
#include "menubutton.h"



class MainForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course; //vettore dei pulsanti corsi
    MyVector <QPushButton *> course_menu; //vettore dei pulsanti per modificare i corsi

    QGridLayout* scroll_layout;  //layou a tabella per i due vettori di bottni


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);
public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm()= default;



signals:

public slots:
};

#endif // MAINFORM_H
