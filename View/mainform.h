#ifndef MAINFORM_H
#define MAINFORM_H

#include <QPushButton>
#include <QFile>
#include <QScrollArea>
#include <QSignalMapper>

#include "Model/myvector.h"
#include "principalform.h"
#include "courseform.h"
#include "menubutton.h"
#include "addcoursecode.h"



class MainForm : public PrincipalForm{
    Q_OBJECT
private:
    MyVector <QPushButton *> course; //vettore dei pulsanti corsi
    MyVector <QPushButton *> course_menu; //vettore dei pulsanti per modificare i corsi

    QGridLayout* scroll_layout;  //layout a tabella per i due vettori di bottni



    virtual void addMenu();

    virtual void addForm();

    virtual void setStyle();

    virtual bool addMenuButton(QPushButton* b, unsigned int i);
public:
    explicit MainForm(User* u,Controller& c,bool &r,QWidget *parent = nullptr);
    ~MainForm()= default;

    virtual MainForm *clone() const;


private slots:
    void del_course(int i);

    void addCourse();

    void send_code(const QString&);

    virtual void confirm_addform(const QString &, const QString &);

    virtual void to_next_page(int index);
    virtual void to_previous_page();
};

#endif // MAINFORM_H
