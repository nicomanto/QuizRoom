#ifndef MAINFORM_H
#define MAINFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>

#include "Model/myvector.h"
#include "principalform.h"
#include "courseform.h"
#include "menubutton.h"



class MainForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course; //vettore dei pulsanti corsi
    MyVector <QPushButton *> course_menu; //vettore dei pulsanti per modificare i corsi

    QGridLayout* scroll_layout;  //layout a tabella per i due vettori di bottni


    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual void addMenuButton(QPushButton* b);
public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm()= default;


private slots:
    virtual void to_next_page();
    virtual void to_previous_page();
};

#endif // MAINFORM_H
